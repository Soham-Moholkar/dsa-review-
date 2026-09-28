#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;if(words.empty())return ans;int w=words[0].size(),total=words.size(),length=w*total;unordered_map<string,int> need;for(auto& word:words)++need[word];for(int start=0;start<w;++start){unordered_map<string,int> have;int l=start,count=0;for(int r=start;r+w<=(int)s.size();r+=w){string token=s.substr(r,w);if(!need.count(token)){have.clear();count=0;l=r+w;continue;}++have[token];++count;while(have[token]>need[token]){--have[s.substr(l,w)];l+=w;--count;}if(count==total){ans.push_back(l);--have[s.substr(l,w)];l+=w;--count;}}}return ans;
    }
};
