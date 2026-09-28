"""Independent small-input oracles for the additional GFG practice exercises."""
from collections import Counter, OrderedDict, deque
from itertools import product
import random
from gfg_expansion_data import ITEMS, S, Q


def palindrome(s): return s == s[::-1]
def substrings(s): return [s[i:j] for i in range(len(s)) for j in range(i+1,len(s)+1)]
def prefix(a):
    return next((a[0][:n] for n in range(len(a[0]),-1,-1) if all(s.startswith(a[0][:n]) for s in a)), '')
def longest_pal(s): return max((v for v in substrings(s) if palindrome(v)),key=len,default='')
def stack_valid(a,b):
    # Enumerate all legal push/pop choices; do not use the greedy reference.
    def visit(i,j,st):
        if j==len(b): return True
        return (i<len(a) and visit(i+1,j,st+(a[i],))) or (bool(st) and st[-1]==b[j] and visit(i,j+1,st[:-1]))
    return visit(0,0,())
def reversals(s):
    if len(s)%2: return -1
    best=len(s)
    for candidate in product('{}',repeat=len(s)):
        balance=0
        for c in candidate:
            balance+=1 if c=='{' else -1
            if balance<0: break
        else:
            if balance==0: best=min(best,sum(a!=b for a,b in zip(s,candidate)))
    return best

def cases_by_module():
    rng=random.Random(20260928)
    extra={S:{},Q:{}}
    for item in ITEMS:
        extra[item['module']][item['index']]=list(item['cases'][1:]) if not item['design'] else []
    def add(mod,index,args,answer): extra[mod][index].append((args,answer))
    for _ in range(30):
        s=''.join(rng.choices('abc',k=rng.randrange(1,9)))
        t=''.join(rng.choices('abc',k=rng.randrange(1,7)))
        spaced=''.join(rng.choices('ab  ',k=rng.randrange(1,10)))
        words=[s,t,''.join(rng.choices('abc',k=5))]
        add(S,46,[spaced],spaced.replace(' ',''))
        add(S,47,[words],prefix(words))
        letters='abcdefghijklmnopqrstuvwxyz'
        sample=letters if rng.randrange(2) else letters[:rng.randrange(26)]
        sample=''.join(rng.sample(sample,len(sample))).upper()+' aaaa!'
        add(S,48,[sample],set(letters)<=set(sample.lower()))
        add(S,49,[s],''.join(dict.fromkeys(s)))
        shift=rng.randrange(len(s)); target=s[shift:]+s[:shift] if rng.randrange(2) else t
        add(S,50,[s,target],len(s)==len(target) and any(s[i:]+s[:i]==target for i in range(len(s))))
        add(S,51,[s],longest_pal(s))
        add(S,52,[s,t],''.join(sorted(set(s)^set(t))) or '-1')
        c1,c2=Counter(s),Counter(t)
        add(S,53,[s,t],sum(abs(c1[c]-c2[c]) for c in c1.keys()|c2.keys()))
        add(S,54,[t,s],sum(sorted(s[i:i+len(t)])==sorted(t) for i in range(len(s)-len(t)+1)))
        k=rng.randrange(1,len(s)+2)
        add(S,55,[s,k],sum(len(set(s[i:i+k]))==k-1 for i in range(len(s)-k+1)))
        add(S,56,[s,k],max((len(v) for v in substrings(s) if len(set(v))==k),default=-1))
        add(S,57,[s],min(len(v) for v in substrings(s) if set(v)==set(s)))
        a,b=rng.randrange(1024),rng.randrange(1024)
        sa,sb='0'*rng.randrange(3)+bin(a)[2:],'0'*rng.randrange(3)+bin(b)[2:]
        add(S,58,[sa,sb],bin(a+b)[2:])
        nums=[rng.randrange(100) for _ in range(3)]
        text='x'.join(str(v) for v in nums)+'z'
        add(S,59,[text],sum(nums))
        add(S,60,[t,s],[i+1 for i in range(len(s)-len(t)+1) if s[i:i+len(t)]==t])
        add(S,61,[s],len(s)-max(i for i in range(len(s)+1) if palindrome(s[:i])))
        import itertools
        encoded=''.join(c+str(len(list(group))) for c,group in itertools.groupby(s))
        add(S,62,[s],encoded)
        # Known rows are independent fixed expectations; repeated random picks stress all slots.
        rows=['1','11','21','1211','111221','312211','13112221','1113213211']
        n=rng.randrange(1,len(rows)+1);add(S,63,[n],rows[n-1])
        a=list(range(1,rng.randrange(2,7)));b=rng.sample(a,len(a))
        add(Q,57,[a,b],stack_valid(a,b))
        # Generate a fully parenthesized expression and its postfix form together.
        def expression(depth):
            if depth==0 or rng.randrange(3)==0:
                c=rng.choice('abcxyz');return c,c
            l,lp=expression(depth-1);r,rp=expression(depth-1);op=rng.choice('+-*/^')
            return '('+l+op+r+')',lp+rp+op
        expr,out=expression(3);add(Q,58,[expr],out)
        braces=''.join(rng.choices('{}',k=rng.randrange(1,9)));add(Q,59,[braces],reversals(braces))
        arr=rng.choices([1,2,3,4],k=rng.randrange(1,10));freq=Counter(arr)
        add(Q,60,[arr],[next((v for v in arr[i+1:] if freq[v]>freq[x]),-1) for i,x in enumerate(arr)])
        values=rng.choices(list(range(-3,5)),k=rng.randrange(1,8))
        add(Q,61,[values],[max(min(values[i:i+k]) for i in range(len(values)-k+1)) for k in range(1,len(values)+1)])
        n=rng.randrange(1,6);mat=[[rng.randrange(2) for _ in range(n)] for _ in range(n)]
        celebs=[c for c in range(n) if all(i==c or (not mat[c][i] and mat[i][c]) for i in range(n))]
        add(Q,62,[mat],celebs[0] if celebs else -1)
        n=rng.randrange(1,25);add(Q,63,[n],[bin(i)[2:] for i in range(1,n+1)])
        n=rng.randrange(1,8);gas=[rng.randrange(5) for _ in range(n)];cost=[rng.randrange(5) for _ in range(n)]
        valid=[]
        for start in range(n):
            tank=0
            for step in range(n):
                i=(start+step)%n;tank+=gas[i]-cost[i]
                if tank<0:break
            else:valid.append(start)
        add(Q,64,[gas,cost],valid[0] if valid else -1)
        k=rng.randrange(1,len(arr)+1);add(Q,65,[arr,k],[len(set(arr[i:i+k])) for i in range(len(arr)-k+1)])
        rows,cols=rng.randrange(1,5),rng.randrange(1,5)
        grid=[[rng.randrange(2) for _ in range(cols)] for _ in range(rows)]
        ones=[(r,c) for r in range(rows) for c in range(cols) if grid[r][c]]
        expected=[[min((abs(r-x)+abs(c-y) for x,y in ones),default=-1) for c in range(cols)] for r in range(rows)]
        add(Q,67,[grid],expected)
    return extra


def design_checks():
    """Generate operation traces with independently modeled outputs for both ADTs."""
    rng=random.Random(19)
    stacks=[[],[]];steps=['S x;']
    for _ in range(180):
        which=rng.randrange(2)
        if rng.randrange(3):
            value=rng.randrange(100);stacks[which].append(value);steps.append(f'x.push{which+1}({value});')
        else:
            result=stacks[which].pop() if stacks[which] else -1;steps.append(f'if(x.pop{which+1}()!={result})return false;')
    steps.append('return true;')
    stack_check=''.join(steps)
    steps=[]
    for capacity in range(5):
        model=OrderedDict();steps.append('{S x('+str(capacity)+');')
        for _ in range(90):
            key=rng.randrange(7)
            if rng.randrange(2):
                value=rng.randrange(100);steps.append(f'x.put({key},{value});')
                if capacity:
                    model[key]=value;model.move_to_end(key)
                    if len(model)>capacity:model.popitem(last=False)
            else:
                result=model.get(key,-1)
                if key in model:model.move_to_end(key)
                steps.append(f'if(x.get({key})!={result})return false;')
        steps.append('}')
    steps.append('return true;')
    return {56:stack_check,66:''.join(steps)}
