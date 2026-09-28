#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int f[256],g[256]; fill(begin(f),end(f),-1);fill(begin(g),end(g),-1); if(s.size()!=t.size()) return false; for(int i=0;i<(int)s.size();++i){unsigned char a=s[i],b=t[i]; if((f[a]!=-1&&f[a]!=b)||(g[b]!=-1&&g[b]!=a)) return false; f[a]=b;g[b]=a;} return true;
    }
};
