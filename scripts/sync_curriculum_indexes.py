#!/usr/bin/env python3
"""Render all later-module navigation tables from their authoritative manifests."""
import json
from pathlib import Path
import re

ROOT=Path(__file__).resolve().parents[1]
STRINGS=json.loads((ROOT/'02_Strings/problem_manifest.json').read_text())
QUEUES=json.loads((ROOT/'04_Stacks_and_Queues/problem_manifest.json').read_text())


def stage(item):
    return item['category'].split('_',1)[1].replace('_',' ')


def local_link(item,module):
    rel=Path(item['folder']).relative_to(module).as_posix()
    return f'[{Path(item["folder"]).name}]({rel}/)'


def replace_table(path,heading,rows,stop):
    text=path.read_text()
    before,after=text.split(heading,1)
    section=after.split(stop,1)
    if len(section)!=2:
        raise RuntimeError(f'Missing section boundary in {path}')
    path.write_text(before+heading+rows+'\n\n'+stop+section[1])


def main():
    string_rows=['| # | Stage | Platform | Problem | Difficulty | Folder |',
                 '|---:|---|---|---|---|---|']
    for item in STRINGS:
        string_rows.append(f'| {item["index"]} | {stage(item)} | {item["platform"]} | {item["title"]} | {item["difficulty"]} | {local_link(item,"02_Strings")} |')
    replace_table(ROOT/'02_Strings/README.md','## Ordered problem list\n\n','\n'.join(string_rows),'## Reference policy')

    queue_rows=['| # | Track | Stage | Platform | Problem | Difficulty | Folder |',
                '|---:|---|---|---|---|---|---|']
    for item in QUEUES:
        queue_rows.append(f'| {item["index"]} | {item["track"]} | {stage(item)} | {item["platform"]} | {item["title"]} | {item["difficulty"]} | {local_link(item,"04_Stacks_and_Queues")} |')
    p=ROOT/'04_Stacks_and_Queues/README.md';text=p.read_text().split('## Ordered problem list\n\n',1)[0]
    p.write_text(text+'## Ordered problem list\n\n'+'\n'.join(queue_rows)+'\n')

    index=ROOT/'INDEX.md';before=index.read_text().split('## 02 Strings —',1)[0]
    lines=[before.rstrip(),'','## 02 Strings — 45 completed reference entries','',
           '[Module theory and navigation](02_Strings/) · [Manifest](02_Strings/problem_manifest.json). Reference availability is separate from personal progress.','',
           '| Global # | Module # | Stage | Platform | Problem | Difficulty | Folder |',
           '|---:|---:|---|---|---|---|---|']
    for item in STRINGS:
        folder=item['folder']
        lines.append(f'| {80+item["index"]} | {item["index"]} | {stage(item)} | {item["platform"]} | {item["title"]} | {item["difficulty"]} | [{Path(folder).name}]({folder}/) |')
    lines += ['','## 04 Stacks & Queues — 55 completed reference entries','',
              '[Module theory and navigation](04_Stacks_and_Queues/) · [Manifest](04_Stacks_and_Queues/problem_manifest.json). Exactly 30 Stack and 25 Queue/Deque learners’ starters.','',
              '| Global # | Module # | Stage | Track | Platform | Problem | Difficulty | Folder |',
              '|---:|---:|---|---|---|---|---|---|']
    for item in QUEUES:
        folder=item['folder']
        lines.append(f'| {125+item["index"]} | {item["index"]} | {stage(item)} | {item["track"]} | {item["platform"]} | {item["title"]} | {item["difficulty"]} | [{Path(folder).name}]({folder}/) |')
    index.write_text('\n'.join(lines)+'\n')

    # Stage tables were produced by an older generator. Keep their teaching
    # paragraphs; update only the link label to the actual platform folder.
    for module,items in (('02_Strings',STRINGS),('04_Stacks_and_Queues',QUEUES)):
        for item in items:
            path=ROOT/module/item['category']/'README.md'
            old=path.read_text()
            name=Path(item['folder']).name
            new=re.sub(r'\[`?\d+_'+re.escape(name)+r'`?\]',f'[{name}]',old)
            if old!=new:path.write_text(new)
    print('Updated 45 Strings and 55 Stack/Queue entries in module and root indexes.')


if __name__=='__main__':main()
