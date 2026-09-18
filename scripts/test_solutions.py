#!/usr/bin/env python3
"""Compile and execute every reference against independent Python oracles."""
import argparse
import json
import os
from pathlib import Path
import re
import subprocess
import sys
import tempfile

ROOT = Path(__file__).resolve().parents[1]
ARRAYS_ROOT = ROOT / '01_Arrays_and_Vectors'
sys.path.insert(0, str(ROOT / 'tests'))
from scenarios import cases
from stress import checks as stress_checks


def literal(value):
    if isinstance(value, (list, tuple)):
        return '{' + ','.join(map(literal, value)) + '}'
    if isinstance(value, bool):
        return 'true' if value else 'false'
    return str(value)


def signature_parts(signature):
    head, params = signature.split('(', 1)
    result, method = head.rsplit(' ', 1)
    types = []
    for param in params.rstrip(')').split(','):
        param = param.strip()
        if '[]' in param:
            types.append('vector<long long>')
        else:
            types.append(re.sub(r'\s*\b\w+$', '', param).replace('&', '').strip())
    return result, method, types


def check_block(ns, signature, case, label):
    result, method, types = signature_parts(signature)
    lines = ['{']
    for i, (typ, value) in enumerate(zip(types, case['args'])):
        lines.append(f'{typ} a{i} = {literal(value)};')
    if case.get('preserve'):
        lines.append('auto original = a0;')
    args = [f'a{i}' for i in range(len(types))]
    if '[]' in signature:
        args[0] += '.data()'
    call = f'{ns}::Solution().{method}({", ".join(args)})'
    mode = case['mode']
    if result == 'void':
        lines += [call + ';', 'auto actual = a0;']
        expected_type = types[0]
    else:
        lines.append('auto actual = ' + call + ';')
        expected_type = result
    expected = case['expected']
    if mode == 'pair':
        b = case['base']
        expression = (f'actual.size()==2 && actual[0]>={b} && actual[1]>={b} && '
                      f'actual[0]<static_cast<int>(a0.size())+{b} && actual[1]<static_cast<int>(a0.size())+{b} && '
                      f'actual[0]!=actual[1] && 1LL*a0[actual[0]-{b}]+a0[actual[1]-{b}]==a1')
    elif mode == 'prefix':
        lines.append(f'vector<int> expected = {literal(expected)};')
        expression = 'actual==static_cast<int>(expected.size()) && a0.size()>=expected.size() && equal(expected.begin(),expected.end(),a0.begin())'
    elif mode == 'one_of':
        lines.append(f'vector<int> expected = {literal(expected)};')
        expression = 'find(expected.begin(),expected.end(),actual)!=expected.end()'
    else:
        lines.append(f'{expected_type} expected = {literal(expected)};')
        if mode == 'unordered':
            lines.append('sort(actual.begin(),actual.end());')
        expression = 'abs(actual-expected)<1e-7' if mode == 'float' else 'actual==expected'
    if case.get('preserve'):
        expression = '(' + expression + ') && a0==original'
    # Identify the exact input even if a sanitizer aborts inside the solution.
    context = json.dumps(label + ' args=' + json.dumps(case['args'], separators=(',', ':')))
    lines.insert(1, f'context = {context};')
    lines.append(f'check({expression});')
    lines.append('}')
    return '\n'.join(lines)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--problem', default='', help='Folder-name substring, e.g. LC_1_Two_Sum')
    parser.add_argument('--pattern', default='', help='Pattern number, e.g. 02')
    parser.add_argument('--trials', type=int, default=40)
    parser.add_argument('--sanitize', action='store_true', help='Undefined-behavior sanitizer and checked STL')
    parser.add_argument('--compiler', default=os.environ.get('CXX', 'g++'))
    args = parser.parse_args()
    if args.trials < 0:
        parser.error('--trials must be nonnegative')
    folders = [p.parent for p in sorted(ARRAYS_ROOT.glob('*/*/*/metadata.json'))
               if args.problem in p.parent.name and p.relative_to(ARRAYS_ROOT).parts[0].startswith(args.pattern)]
    if not folders:
        parser.error('No matching problem folders')
    total_cases = total_files = failed = 0
    groups = sorted({p.relative_to(ARRAYS_ROOT).parts[0] for p in folders})
    for group in groups:
        source = ['#include <bits/stdc++.h>', 'using namespace std;',
                  'string context; int failures=0; long long checks=0;',
                  'void check(bool ok) { ++checks; if(!ok) { ++failures; cerr<<"FAIL "<<context<<"\\n"; } }']
        count = 0
        calls = []
        checks_count = 0
        for folder in folders:
            if folder.relative_to(ARRAYS_ROOT).parts[0] != group:
                continue
            meta = json.loads((folder/'metadata.json').read_text())
            inputs = cases(folder.name, args.trials)
            for path in sorted(folder.glob('0[234]_*.cpp')):
                ns = f'solution_{count}'
                code = path.read_text().replace('#include <bits/stdc++.h>', '')
                source.append(f'namespace {ns} {{\n{code}\n}}')
                blocks = [check_block(ns, meta['signature'], c, f'{folder.name}/{path.name} case {i}') for i,c in enumerate(inputs)]
                blocks.extend(stress_checks(folder.name, ns, int(path.name[:2])))
                source.append(f'void run_{count}() {{\n' + '\n'.join(blocks) + '\n}')
                calls.append(f'run_{count}();')
                checks_count += len(blocks)
                count += 1
        source.append('int main() {\n' + '\n'.join(calls) + '\ncout<<checks<<" checks, "<<failures<<" failures\\n"; return failures ? 1 : 0; }')
        with tempfile.TemporaryDirectory(prefix='dsa-test-') as tmp:
            cpp, exe = Path(tmp)/'tests.cpp', Path(tmp)/'tests'
            cpp.write_text('\n'.join(source))
            flags = ['-std=c++17', '-O0', '-g0']
            if args.sanitize:
                flags += ['-fsanitize=undefined', '-fno-sanitize-recover=all', '-D_GLIBCXX_ASSERTIONS']
            print(f'{group}: compiling {count} references / {checks_count} checks', flush=True)
            subprocess.run([args.compiler, *flags, str(cpp), '-o', str(exe)], check=True, timeout=180)
            run = subprocess.run([str(exe)], timeout=60)
            failed += run.returncode != 0
        total_files += count
        total_cases += checks_count
    print(f'TOTAL: {len(folders)} problems, {total_files} references, {total_cases} checks, {failed} failing groups', flush=True)
    return bool(failed)


if __name__ == '__main__':
    try:
        sys.exit(main())
    except (subprocess.SubprocessError, OSError, ValueError) as exc:
        print(f'Test runner failed: {exc}', file=sys.stderr)
        sys.exit(1)
