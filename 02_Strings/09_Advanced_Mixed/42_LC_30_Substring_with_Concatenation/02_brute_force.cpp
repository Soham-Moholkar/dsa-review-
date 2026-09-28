#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;if(words.empty())return ans;int len=words.size()*words[0].size();map<string,int> required;for(auto& w:words)++required[w];for(int i=0;i+len<=s.size();++i){auto remain=required;int j=0;for(;j<len;j+=words[0].size()){auto token=s.substr(i+j,words[0].size());if(remain[token]--<=0)break;}if(j==len)ans.push_back(i);}return ans;
    }
};
