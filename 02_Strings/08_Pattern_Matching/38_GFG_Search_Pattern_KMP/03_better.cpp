#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> search(string &pat, string &txt) {
        vector<int> ans;if(pat.empty())return ans;vector<int> pi(pat.size());for(int i=1;i<(int)pat.size();++i){int j=pi[i-1];while(j&&pat[i]!=pat[j])j=pi[j-1];if(pat[i]==pat[j])++j;pi[i]=j;}int j=0;for(int i=0;i<(int)txt.size();++i){while(j&&txt[i]!=pat[j])j=pi[j-1];if(txt[i]==pat[j])++j;if(j==(int)pat.size()){ans.push_back(i-j+1);j=pi[j-1];}}return ans;
    }
};
