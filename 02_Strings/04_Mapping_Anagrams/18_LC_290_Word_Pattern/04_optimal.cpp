#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream in(s); vector<string> words; string w; while(in>>w) words.push_back(w); if(words.size()!=pattern.size()) return false; unordered_map<char,string> f;unordered_map<string,char> g; for(int i=0;i<(int)words.size();++i){char c=pattern[i]; if((f.count(c)&&f[c]!=words[i])||(g.count(words[i])&&g[words[i]]!=c)) return false; f[c]=words[i];g[words[i]]=c;} return true;
    }
};
