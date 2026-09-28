#!/usr/bin/env python3
"""Execute independent fixed examples against all newer-module C++ references."""
import argparse, json, pathlib, re, subprocess, tempfile
ROOT=pathlib.Path(__file__).resolve().parents[1]
# Input objects and expected results are independent of reference implementations.
S={
1:((list('hello'),),list('olleh')),2:(('Hello',),'hello'),3:(('Hello World',),5),4:(('abc','pqr'),'apbqcr'),
5:(('the sky is blue',),'blue is sky the'),6:(('leetcode',),0),7:(('aa','aab'),True),8:(('abacbc',),True),
9:(('nlaebolko',),1),10:(('tree',),'eert'),11:(('A man, a plan, a canal: Panama',),True),12:(('abca',),True),
13:((['abc','car','ada','racecar','cool'],),'ada'),14:(('IceCreAm',),'AceCreIm'),15:(('ab-cd',),'dc-ba'),
16:(('anagram','nagaram'),True),17:(('egg','add'),True),18:(('abba','dog cat cat dog'),True),
19:((['eat','tea','tan','ate','nat','bat'],),[['eat','tea','ate'],['tan','nat'],['bat']]),
20:(('abc','bca'),True),21:(('xyzzaz',),1),22:(('abciiidef',3),3),23:(('WBBWWBBWBW',7),3),
24:(('ab','eidbaooo'),True),25:(('cbaebabacd','abc'),[0,6]),26:(('abcabcbb',),3),
27:(('ABAB',2),4),28:(('ADOBECODEBANC','ABC'),'BANC'),29:(('abcabc',),10),30:(('TTFF',2),4),
31:(('MCMXCIV',),1994),32:(('   -42',),-42),33:((3749,),'MMMDCCXLIX'),
34:(('11','123'),'134'),35:(('123','456'),'56088'),36:(('sadbutsad','sad'),0),37:(('abab',),True),
38:(('ab','abcab'),[0,3]),39:(('level',),'l'),40:(('AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT',),['AAAAACCCCC','CCCCCAAAAA']),
41:(('abcd','cdabcdab'),3),42:(('barfoothefoobarman',['foo','bar']),[0,9]),
43:((['abc','deq','mee','aqq','dkd','ccc'],'abb'),['mee','aqq']),
44:(('ababcbacadefegdehijhklij',),[9,7,8]),45:(('PAYPALISHIRING',3),'PAHNAPLSIIGYIR'),
}
Q={
3:((['5','2','C','D','+'],),30),4:(('abbaca',),'ca'),5:(([1,2,3,4,5],[4,5,3,2,1]),True),
6:(([1,2,3],9),[9,1,2,3]),7:(([1,2,3],),[3,2,1]),8:(([1,2,3,4],),[1,3,4]),9:(([3,1,2],),[1,2,3]),
10:(('()[]{}',),True),11:(('((a+b))',),True),12:(('())',),1),13:((['2','1','+','3','*'],),9),14:(('3+2*2',),7),
15:(([2,1,4,3],),[4,4,-1,-1]),16:(([2,1,4,3],),[1,-1,3,-1]),17:(([2,1,4,3],),[-1,2,-1,4]),18:(([2,1,4,3],),[-1,-1,1,1]),
19:(([1,2,1],),[2,-1,2]),21:(([73,74,75,71,69,72,76,73],),[1,1,4,2,1,1,0,0]),
22:(([2,1,5,6,2,3],),10),23:(([['1','0','1','0','0'],['1','0','1','1','1'],['1','1','1','1','1'],['1','0','0','1','0']],),6),
24:(([3,1,2,4],),17),25:(([1,2,3],),4),26:(([0,1,0,2,1,0,1,3,2,1,2,1],),6),
28:(([5,10,-5],),[5,10]),29:(('1432219',3),'1219'),30:(('3[a]2[bc]',),'aaabcbc'),
33:(([2,3,2],2),6),34:(([1,1,0,0],[0,1,0,1]),0),
35:(([1,2,3],),[3,2,1]),36:(([1,2,3,4,5],3),[3,2,1,4,5]),37:(([1,2,3,4],),[1,3,2,4]),
41:((['push_back 2','push_front 1','push_back 3'],),[1,2,3]),
42:(([-8,2,3,-6,10],2),[-8,0,-6,-6]),43:(([1,3,-1,-3,5,3,6,7],3),[3,3,5,5,6,7]),
44:(([8,2,4,7],4),2),45:(([2,-1,2],3),3),46:(('aabc',),'a#bb'),
48:(([17,13,11,2,3,5,7],),[2,13,3,11,5,17,7]),49:(('RDD',),'Dire'),50:(([1,2,3,4],2),[3,4]),
53:(([[2,1,1],[1,1,0],[0,1,1]],),4),54:(([['+','+','.'],['.','.','.'],['+','+','+']],[1,0]),2),
55:(([[1,0,1],[0,0,0],[1,0,1]],),2),
}
EXTRA={
 '02_Strings':{
  1:[(([],),[])], 3:[(('   ',),0)], 6:[(('aabb',),-1)],
  11:[(('',),True)], 12:[(('abc',),False)], 16:[(('aacc','ccac'),False)],
  22:[(('aeiou',2),2)], 24:[(('ab','eidboaoo'),False)],
  26:[(('bbbbb',),1)], 28:[(('a','aa'),'')],
  32:[(('9'*100,),2147483647),(('-'+'9'*100,),-2147483648)],
  35:[(('0','999'),'0')], 37:[(('a',),False)],
  38:[(('aa','aaaa'),[0,1,2])], 42:[(('wordgoodgoodgoodbestword',['word','good','best','word']),[])],
  45:[(('A',1),'A')],
 },
 '04_Stacks_and_Queues':{
  4:[(('azxxzy',),'ay')], 6:[(([],3),[3])], 7:[(([],),[])],
  10:[(('([)]',),False)], 12:[(('(((',),3)],
  15:[(([2,2,3],),[3,3,-1])], 16:[(([2,2,1],),[1,1,-1])],
  17:[(([2,2,1],),[-1,-1,2])], 18:[(([2,2,3],),[-1,-1,2])],
  22:[(([2,2,2],),6)], 24:[(([2,2,2],),12)],
  25:[(([1,1],),0)], 26:[(([1],),0)],
  35:[(([],),[])], 36:[(([1,2,3],1),[1,2,3])],
  42:[(([-1,-2,-3],1),[-1,-2,-3])],
  43:[(([1,1,1],2),[1,1])], 44:[(([1,1,1],0),3)],
  45:[(([-1,-2,-3],1),-1)], 46:[(('zz',),'z#')],
  50:[(([1,2,3],0),[])], 53:[(([[0,2],[0,0]],),0)],
  55:[(([[1,1],[1,1]],),-1),(([[0,0],[0,0]],),-1)],
 }
}
# Design exercises use methods, so we exercise their real public API instead of a
# synthetic Solution adapter. These expressions return bool after all operations.
DESIGN={
1:'S x; x.push(2);x.push(7);if(x.top()!=7||x.size()!=2)return false;x.pop();return x.top()==2&&!x.empty();',
2:'S x;x.push(3);x.push(5);x.pop();return x.top()==3&&x.size()==1;',
20:'S x;int v[]={100,80,60,70,60,75,85};int a[]={1,1,1,2,1,4,6};for(int i=0;i<7;++i)if(x.next(v[i])!=a[i])return false;return true;',
27:'S x;x.push(-2);x.push(0);x.push(-3);if(x.getMin()!=-3)return false;x.pop();return x.top()==0&&x.getMin()==-2;',
31:'S x;x.push(2);x.push(7);if(x.front()!=2||x.back()!=7||x.size()!=2)return false;x.pop();return x.front()==7;',
32:'S x;x.push(2);x.push(7);x.pop();return x.front()==7&&x.back()==7&&x.size()==1;',
38:'S x(3);return x.enQueue(1)&&x.enQueue(2)&&x.enQueue(3)&&!x.enQueue(4)&&x.Rear()==3&&x.isFull();',
39:'S x;x.push(1);x.push(2);return x.peek()==1&&x.pop()==1&&!x.empty();',
40:'S x;x.push(1);x.push(2);return x.top()==2&&x.pop()==2&&!x.empty();',
47:'S x;return x.ping(1)==1&&x.ping(100)==2&&x.ping(3001)==3&&x.ping(3002)==3;',
51:'S x(3);return x.insertLast(1)&&x.insertLast(2)&&x.insertFront(3)&&!x.insertFront(4)&&x.getRear()==2&&x.isFull();',
52:'S x;x.pushFront(1);x.pushBack(2);x.pushMiddle(3);return x.popMiddle()==3&&x.popFront()==1&&x.popBack()==2;',
}

def cpp_value(value,typ):
    typ=typ.replace('&','').strip()
    if typ in ('int','long long'):return str(value)
    if typ=='bool':return 'true' if value else 'false'
    if typ=='string':return json.dumps(value)
    if typ=='vector<char>':return typ+'{'+','.join("'"+c.replace("'","\\'")+"'" for c in value)+'}'
    if typ=='vector<vector<char>>':return typ+'{'+','.join(cpp_value(row,'vector<char>') for row in value)+'}'
    if typ.startswith('vector<'):
        child=typ[len('vector<'):-1]
        return typ+'{'+','.join(cpp_value(x,child) for x in value)+'}'
    raise ValueError(typ)

def parts(signature):
    head,rest=signature.split('(',1)
    name=head.split()[-1];returned=head[:head.rfind(name)].strip()
    types=[re.sub(r'\s*\w+$','',p.strip()).strip() for p in rest.split(')',1)[0].split(',')]
    return returned,name,types

def make_check(item,case,ns):
    number=item['index'];signature=item['signature'];mod=item['folder'].split('/')[0]
    if signature.startswith('class '):
        klass=signature.split()[1]; expr=DESIGN[number].replace('S ',ns+'::'+klass+' ')
        return f'check([&](){{{expr}}}(),"{mod} #{number}");'
    inputs,expected=case
    ret,method,types=parts(signature)
    declarations=[]
    for i,(value,typ) in enumerate(zip(inputs,types)):
        if typ.replace('&','').strip() in ('stack<int>','queue<int>'):
            kind=typ.replace('&','').strip();declarations.append(f'{kind} a{i};')
            for x in value:declarations.append(f'a{i}.push({x});')
        else:declarations.append(f'{typ.replace("&", "").strip()} a{i}={cpp_value(value,typ)};')
    call=f'{ns}::Solution().{method}('+','.join(f'a{i}' for i in range(len(inputs)))+')'
    if ret=='void':
        declarations.append(call+';')
        if types[0].startswith(('stack<','queue<')):
            kind=types[0].split('<')[0];declarations.append(f'vector<int> actual;while(!a0.empty()){{actual.push_back(a0.{"top" if kind=="stack" else "front"}());a0.pop();}}')
            if kind=='stack':declarations.append('reverse(actual.begin(),actual.end());')
            expression='actual=='+cpp_value(expected,'vector<int>')
        else:expression='a0=='+cpp_value(expected,types[0])
    else:
        declarations.append(f'auto actual={call};')
        if mod=='02_Strings' and number==10:
            expression='actual.size()==4 && count(actual.begin(),actual.end(),\'e\')==2 && count(actual.begin(),actual.end(),\'t\')==1 && count(actual.begin(),actual.end(),\'r\')==1 && actual[0]==actual[1]'
        elif mod=='02_Strings' and number==19:
            declarations.append('for(auto& group:actual)sort(group.begin(),group.end());sort(actual.begin(),actual.end());')
            declarations.append('vector<vector<string>> expected='+cpp_value(expected,ret)+';for(auto& group:expected)sort(group.begin(),group.end());sort(expected.begin(),expected.end());')
            expression='actual==expected'
        elif mod=='02_Strings' and number==40:
            declarations.append('sort(actual.begin(),actual.end());')
            declarations.append('vector<string> expected='+cpp_value(expected,ret)+';sort(expected.begin(),expected.end());')
            expression='actual==expected'
        else:expression='actual=='+cpp_value(expected,ret)
    return f'check([&](){{{"".join(declarations)}return {expression};}}(),"{mod} #{number}");'

def main():
    parser=argparse.ArgumentParser();parser.add_argument('--module',choices=['strings','queues','both'],default='both');parser.add_argument('--sanitize',action='store_true');parser.add_argument('--problem',default='',help='Folder-name substring, matching the Arrays/Vectors runner');args=parser.parse_args()
    modules=[]
    if args.module in ('strings','both'):modules.append(('02_Strings',S))
    if args.module in ('queues','both'):modules.append(('04_Stacks_and_Queues',Q))
    total=0
    for mod,cases in modules:
        manifest=json.loads((ROOT/mod/'problem_manifest.json').read_text())
        assert len(manifest)==len(cases)+len([n for n in DESIGN if mod!='02_Strings' and n in {x['index'] for x in manifest}])
        manifest=[x for x in manifest if args.problem in pathlib.Path(x['folder']).name]
        groups={x['category'] for x in manifest}
        for stage in sorted(groups):
            entries=[x for x in manifest if x['category']==stage]
            lines=['#include <bits/stdc++.h>','using namespace std;','int failed=0,passed=0;void check(bool ok,const char* label){if(ok)++passed;else{++failed;cerr<<"FAIL "<<label<<"\\n";}}']
            checks=[]
            for item in entries:
                n=item['index'];total+=1
                for level,file in [(2,'02_brute_force.cpp'),(3,'03_better_approach.cpp'),(4,'04_optimal_solution.cpp')]:
                    ns=f'm{n}_{level}';code=(ROOT/item['folder']/file).read_text().replace('#include <bits/stdc++.h>','').replace('using namespace std;','')
                    lines.append(f'namespace {ns} {{\n{code}\n}}')
                    checks.append(make_check(item,cases.get(n),ns))
                    checks.extend(make_check(item,case,ns) for case in EXTRA.get(mod,{}).get(n,[]))
            lines.append('int main(){'+''.join(checks)+'cout<<"'+stage+': "<<passed<<" passed, "<<failed<<" failed\\n";return failed?1:0;}')
            with tempfile.TemporaryDirectory(prefix='dsa-ref-') as tmp:
                src=pathlib.Path(tmp)/'test.cpp';exe=pathlib.Path(tmp)/'test';src.write_text('\n'.join(lines))
                flags=['-std=c++17','-O0','-g0']
                if args.sanitize:flags+=['-fsanitize=undefined','-fno-sanitize-recover=all','-D_GLIBCXX_ASSERTIONS']
                subprocess.run(['g++',*flags,str(src),'-o',str(exe)],check=True,timeout=180)
                subprocess.run([str(exe)],check=True,timeout=60)
    if total==0:parser.error('No matching problem folders')
    print(f'TOTAL: {total} problems, {total*3} references with fixed behavior checks')

if __name__=='__main__':main()
