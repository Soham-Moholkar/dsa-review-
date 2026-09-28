#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        auto match=[&](const string& a){if(a.size()!=pattern.size())return false;int f[256],g[256];fill(begin(f),end(f),-1);fill(begin(g),end(g),-1);for(int i=0;i<(int)a.size();++i){unsigned char x=a[i],y=pattern[i];if((f[x]!=-1&&f[x]!=y)||(g[y]!=-1&&g[y]!=x))return false;f[x]=y;g[y]=x;}return true;};vector<string> out;for(auto& w:words)if(match(w))out.push_back(w);return out;
    }
};
