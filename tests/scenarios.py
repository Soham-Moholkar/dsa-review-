"""Deterministic input generation and independent, deliberately simple oracles.

These cases follow the handbook contracts; see docs/CONTRACTS.md for platform
variants. Small randomized inputs let even exponential teaching baselines run.
"""
from collections import Counter
from itertools import combinations, permutations, accumulate
from functools import reduce
from operator import xor
import random


def cases(name, trials=40):
    rng = random.Random(20260916)  # reproducible across Python processes
    out = []
    def add(args, expected, mode='value', **extra):
        out.append(dict(args=args, expected=expected, mode=mode, **extra))
    def arrays(lo=-5, hi=5, nmin=1, nmax=8):
        return [[rng.randint(lo, hi) for _ in range(rng.randint(nmin, nmax))] for _ in range(trials)]
    def subs(a):
        return [a[i:j] for i in range(len(a)) for j in range(i+1, len(a)+1)]
    def merge(a):
        # Connected components of overlapping intervals, independent of sorted scan.
        a = [x[:] for x in a]
        while True:
            pair = next(((i,j) for i in range(len(a)) for j in range(i+1,len(a))
                         if max(a[i][0],a[j][0]) <= min(a[i][1],a[j][1])), None)
            if pair is None: return sorted(a)
            i,j = pair
            a[i] = [min(a[i][0],a[j][0]), max(a[i][1],a[j][1])]
            a.pop(j)

    if name in ('GFG_Largest_Element_in_Array','GFG_Min_and_Max_in_Array','GFG_Second_Largest'):
        for a in [[5],[-8,-3,-9],[5,5,5],[12,35,1,10,34,1],[-2147483648,0]]+arrays():
            u=sorted(set(a))
            e=max(a) if 'Largest_Element' in name else ([min(a),max(a)] if 'Min_and_Max' in name else (u[-2] if len(u)>1 else -1))
            add([a],e)
    elif name == 'GFG_Reverse_an_Array':
        for a in [[],[1],[1,2,3,4]]+arrays(): add([a],a[::-1],'mutation')
    elif name.startswith('LC_1295_'):
        for a in [[12,345,2,6,7896],[1,9,10,99,100,999,1000,9999,10000,99999,100000]]+arrays(1,100000):
            add([a],sum(len(str(x))%2==0 for x in a))
    elif name.startswith('LC_189_'):
        for a in [[],[1],[1,2,3,4,5,6,7]]+arrays():
            for k in [0,1,len(a),len(a)+2]:
                d=k%len(a) if a else 0
                add([a,k],a[-d:]+a[:-d] if d else a[:],'mutation')
    elif name in ('LC_283_Move_Zeroes','GFG_Move_All_Zeroes_to_End'):
        for a in [[],[0],[0,1,0,3,12],[0,0,0]]+arrays(-2,2):
            add([a],[x for x in a if x]+[0]*a.count(0),'mutation')
    elif name.startswith('LC_485_'):
        for a in [[0],[1],[1,1,0,1,1,1]]+arrays(0,1):
            add([a],max([len(s) for s in subs(a) if all(s)]+[0]))
    elif name == 'GFG_Frequencies_in_a_Limited_Array':
        for a in [[1],[2,3,2,3,5],[4,4,4,4],[8,8,8],[2,8,2],[1,2,3,4]]+arrays(1,12):
            add([a,len(a),max(a)], [a.count(i) for i in range(1,len(a)+1)],'mutation')
    elif 'Longest_Consecutive' in name:
        for a in [[],[100,4,200,1,3,2],[1,2,0,1],[-2147483648,2147483647]]+arrays():
            u=sorted(set(a)); best=run=0; prev=None
            for x in u:
                run=run+1 if prev is not None and x==prev+1 else 1
                best=max(best,run);prev=x
            add([a],best)
    elif name in ('GFG_Majority_Element','LC_169_Majority_Element'):
        for a in [[2,2,1,1,1,2,2],[1],[3,3,4],[1,2,3,4]]+arrays():
            c=Counter(a); e=next((x for x,n in c.items() if n>len(a)//2),-1)
            if name.startswith('LC') and max(c.values())<=len(a)//2: continue
            add([a],e)
    elif 'Two_Sum' in name or name=='GFG_Pair_Sum_in_Sorted_Array':
        for a in [[2,7,11,15],[3,3],[1,2,5],[-5,-1,2,8]]+arrays(nmin=2):
            if 'Sorted' in name: a=sorted(a)
            for target in [a[0]+a[1],13,0]:
                found=any(x+y==target for x,y in combinations(a,2))
                if name.startswith('LC'):
                    if found: add([a,target],None,'pair',base=1 if name.startswith('LC_167') else 0)
                else: add([a,target],found)
    elif name.startswith('LC_217_'):
        for a in [[],[1],[1,2,3,1]]+arrays(): add([a],len(set(a))<len(a))
    elif 'Remove_Duplicates_from_Sorted_Array' in name:
        for a in [[],[1],[1,1,2]]+arrays():
            a=sorted(a);add([a],sorted(set(a)),'prefix')
    elif name=='GFG_Trapping_Rain_Water':
        for a in [[0],[3,0,2,0,4],[4,2,0,3,2,5]]+arrays(0,8):
            add([a],sum(min(max(a[:i+1]),max(a[i:]))-x for i,x in enumerate(a)))
    elif name.startswith('LC_11_'):
        for a in [[1,1],[1,8,6,2,5,4,8,3,7]]+arrays(0,8,nmin=2):
            add([a],max(min(a[i],a[j])*(j-i) for i in range(len(a)) for j in range(i+1,len(a))))
    elif name.startswith('LC_15_'):
        for a in [[0,0,0,0],[-1,0,1,2,-1,-4],[1,2,3]]+arrays(nmin=3):
            add([a],[list(t) for t in sorted({tuple(sorted(t)) for t in combinations(a,3) if sum(t)==0})],'unordered')
    elif name in ('GFG_Count_Distinct_Elements_in_Every_Window','GFG_First_Negative_Integer_in_Every_Window_of_Size_K','GFG_Max_Sum_Subarray_of_Size_K','LC_643_Maximum_Average_Subarray_I'):
        for a in [[-5],[-2,-7,-1],[12,-1,-7,8,-15,30,16,28]]+arrays():
            for k in sorted({1,len(a),max(1,len(a)//2)}):
                windows=[a[i:i+k] for i in range(len(a)-k+1)]
                if name.startswith('GFG_Count'): add([a,k],[len(set(w)) for w in windows])
                elif name.startswith('GFG_First'): add([a,len(a),k],[next((x for x in w if x<0),0) for w in windows])
                elif name.startswith('GFG_Max'): add([k,a,len(a)],max(map(sum,windows)))
                else: add([a,k],max(map(sum,windows))/k,'float')
    elif name in ('GFG_Smallest_Subarray_with_Sum_Greater_Than_X','LC_209_Minimum_Size_Subarray_Sum'):
        for a in [[1],[2,3,1,2,4,3],[1,1,1]]+arrays(1,10):
            for t in [1,sum(a),sum(a)+1,7]:
                good=[len(s) for s in subs(a) if (sum(s)>t if name.startswith('GFG') else sum(s)>=t)]
                add([t,a],min(good,default=0))
        if name.startswith('GFG'):add([0,[0,0,1]],1)
    elif name.startswith('LC_1004_'):
        for a in [[0],[1],[1,1,0,0,1,1,1]]+arrays(0,1):
            for k in [0,1,len(a)]: add([a,k],max([len(s) for s in subs(a) if s.count(0)<=k]+[0]))
    elif name.startswith('LC_904_'):
        for a in [[1],[1,2,1],[0,1,2,2]]+arrays(0,4):
            add([a],max(len(s) for s in subs(a) if len(set(s))<=2))
    elif name in ('GFG_Count_Subarrays_with_Given_XOR','GFG_Longest_Subarray_with_Sum_K','LC_560_Subarray_Sum_Equals_K'):
        for a in [[0,0,0],[1,-1,0],[4,2,2,6,4]]+arrays(0 if 'XOR' in name else -5,5):
            if 'XOR' in name and min(a)<0:continue
            for k in [0,3,6]:
                ss=subs(a)
                if 'XOR' in name:e=sum(reduce(xor,s,0)==k for s in ss)
                elif 'Longest' in name:e=max([len(s) for s in ss if sum(s)==k]+[0])
                else:e=sum(sum(s)==k for s in ss)
                add([a,k],e)
    elif name in ('GFG_Equilibrium_Point','LC_724_Find_Pivot_Index'):
        for a in [[1],[1,7,3,6,5,6],[1,2,3],[0,0]]+arrays():
            e=next((i for i in range(len(a)) if sum(a[:i])==sum(a[i+1:])),-1)
            add([a],e+1 if e!=-1 and name.startswith('GFG') else e)
    elif name=='GFG_Subarray_with_0_Sum':
        for a in [[0],[1,-1],[1,2,3]]+arrays():add([a],any(sum(s)==0 for s in subs(a)))
    elif name.startswith('LC_1480_'):
        for a in [[1],[1,2,3,4]]+arrays():add([a],list(accumulate(a)))
    elif name.startswith('LC_525_'):
        for a in [[0],[1],[0,1],[0,1,0]]+arrays(0,1):
            add([a],max([len(s) for s in subs(a) if s.count(0)==s.count(1)]+[0]))
    elif name in ('GFG_Kadanes_Algorithm','LC_53_Maximum_Subarray','GFG_Maximum_Circular_Subarray_Sum','LC_918_Maximum_Sum_Circular_Subarray','GFG_Maximum_Product_Subarray','LC_152_Maximum_Product_Subarray','GFG_Stock_Buy_and_Sell_Max_One_Transaction','LC_121_Best_Time_to_Buy_and_Sell_Stock'):
        for a in [[-3,-2,-5],[0],[-2,0,-1],[5,-3,5],[2,3,-2,4]]+arrays(-3,3):
            if 'Stock' in name:
                a=[abs(x) for x in a];e=max([a[j]-a[i] for i in range(len(a)) for j in range(i+1,len(a))]+[0])
            elif 'Product' in name:
                import math
                e=max(math.prod(s) for s in subs(a))
            elif 'Circular' in name:
                e=max(sum((a+a)[i:i+k]) for i in range(len(a)) for k in range(1,len(a)+1))
            else:e=max(map(sum,subs(a)))
            add([a],e)
    elif name.startswith(('GFG_Binary_Search','LC_704_','GFG_First_and_Last','LC_34_','GFG_Search_in_Rotated','LC_33_')):
        for a in [[1],[1,2,3,4,5],[2,2,2]]+arrays():
            if 'Rotated' in name or name.startswith('LC_704'):a=sorted(set(a))
            else:a=sorted(a)
            if 'Rotated' in name:
                k=rng.randrange(len(a));a=a[k:]+a[:k]
            for t in [a[0],a[-1],17]:
                hits=[i for i,x in enumerate(a) if x==t]
                e=([hits[0],hits[-1]] if hits else [-1,-1]) if ('First_and_Last' in name or name.startswith('LC_34')) else (hits[0] if hits else -1)
                add([a,t],e)
    elif name in ('GFG_Peak_Element','LC_162_Find_Peak_Element'):
        for a in [[1],[1,2,3],[3,2,1],[1,3,2,4,1]]+arrays():
            if name.startswith('LC') and any(a[i]==a[i+1] for i in range(len(a)-1)):continue
            strict=name.startswith('LC')
            peaks=[i for i in range(len(a)) if (i==0 or (a[i]>a[i-1] if strict else a[i]>=a[i-1])) and (i==len(a)-1 or (a[i]>a[i+1] if strict else a[i]>=a[i+1]))]
            add([a],peaks,'one_of')
    elif name=='GFG_Chocolate_Distribution_Problem':
        for a in [[1],[7,3,2,4,9,12,56]]+arrays(1,20):
            for m in sorted({1,len(a),max(1,len(a)//2)}):
                add([a,m],min(max(s)-min(s) for s in combinations(a,m)))
    elif name in ('GFG_Insert_and_Merge_Interval','LC_57_Insert_Interval','GFG_Overlapping_Intervals','LC_56_Merge_Intervals'):
        samples=[[],[[1,3],[2,6],[8,10]],[[1,4],[4,5]],[[1,10],[2,3]]]
        samples += [[sorted([rng.randint(0,15),rng.randint(0,15)]) for _ in range(rng.randint(1,6))] for _ in range(trials)]
        for a in samples:
            if 'Insert' in name:
                a=merge(a)
                for new in [[0,0],[3,8],[20,25]]:add([a,new],merge(a+[new]))
            else:add([a],merge(a))
    elif name in ('GFG_Sort_0s_1s_and_2s','LC_75_Sort_Colors'):
        for a in [[0],[2,0,2,1,1,0]]+arrays(0,2):add([a],sorted(a),'mutation')
    elif name.startswith('LC_31_'):
        for a in [[1],[1,2,3],[3,2,1],[1,1,5]]+arrays(0,3,nmax=6):
            ps=sorted(set(permutations(a)));e=ps[(ps.index(tuple(a))+1)%len(ps)]
            add([a],list(e),'mutation')
    elif name=='GFG_Find_Duplicates_in_an_Array':
        for n in range(1,10):
            for _ in range(8):
                a=[rng.randrange(n) for _ in range(n)]
                add([a],sorted(x for x,c in Counter(a).items() if c>1) or [-1])
    elif name in ('GFG_Missing_Number','LC_268_Missing_Number'):
        for n in range(1,10):
            for missing in range(1 if name.startswith('GFG') else 0,n+1):
                a=[i for i in range(1 if name.startswith('GFG') else 0,n+1) if i!=missing]
                rng.shuffle(a);add([a],missing)
    elif name=='GFG_Missing_and_Repeating':
        for n in range(2,10):
            for _ in range(8):
                missing,repeating=rng.sample(range(1,n+1),2)
                a=[repeating if x==missing else x for x in range(1,n+1)];rng.shuffle(a)
                add([a],[repeating,missing])
    elif name in ('GFG_Smallest_Positive_Missing_Number','LC_41_First_Missing_Positive'):
        for a in [[1],[3,4,-1,1],[1,2,0],[-2147483648,2147483647,1]]+arrays():
            add([a],next(x for x in range(1,len(a)+2) if x not in a))
    elif name.startswith('LC_287_'):
        for n in range(1,10):
            for d in range(1,n+1):
                a=list(range(1,n+1))+[d];rng.shuffle(a);add([a],d,preserve=True)
            add([[1]*(n+1)],1,preserve=True)
    elif name.startswith('LC_448_'):
        for n in range(1,10):
            for _ in range(6):
                a=[rng.randint(1,n) for _ in range(n)];add([a],[x for x in range(1,n+1) if x not in a])
    elif name in ('GFG_Boolean_Matrix','LC_73_Set_Matrix_Zeroes','GFG_Rotate_by_90_Degree','LC_48_Rotate_Image','GFG_Search_in_a_Row_Column_Sorted_Matrix','LC_240_Search_a_2D_Matrix_II','GFG_Spirally_Traversing_a_Matrix','LC_54_Spiral_Matrix'):
        for rows,cols in [(1,1),(1,5),(5,1),(2,3),(3,2),(3,3),(4,4)]:
            for _ in range(6):
                if 'Rotate' in name and rows!=cols:continue
                a=[[rng.randint(0,2) for _ in range(cols)] for _ in range(rows)]
                if 'Search' in name:
                    # Sorted rows and columns, without requiring row-major sorting.
                    a=[[i*3+j*2-7 for j in range(cols)] for i in range(rows)]
                    for t in [-99,a[0][0],a[-1][-1],a[rows//2][cols//2],0]:add([a,t],any(t in row for row in a))
                elif 'Rotate' in name:
                    e=[list(row) for row in zip(*a)]
                    e=e[::-1] if name.startswith('GFG') else [row[::-1] for row in e]
                    add([a],e,'mutation')
                elif 'Spiral' in name:
                    # Peel a row and rotate the remainder anticlockwise.
                    b=[row[:] for row in a];e=[]
                    while b:
                        e+=b.pop(0)
                        b=[list(row) for row in zip(*b)][::-1] if b else []
                    add([a],e)
                else:
                    mark=1 if name.startswith('GFG') else 0
                    if mark==1:a=[[x%2 for x in row] for row in a]
                    e=[[mark if mark in a[i] or any(a[k][j]==mark for k in range(rows)) else a[i][j] for j in range(cols)] for i in range(rows)]
                    add([a],e,'mutation')
    else:
        raise ValueError(f'No test generator for {name}')
    if "Two_Sum" in name or name=="GFG_Pair_Sum_in_Sorted_Array":
        a=[-2147483648,0,2147483647]
        if name.startswith("LC"):
            add([a,-1],None,"pair",base=1 if name.startswith("LC_167") else 0)
        else:
            add([a,-1],True)
            add([a,-2147483648],True)
    assert out, name
    return out
