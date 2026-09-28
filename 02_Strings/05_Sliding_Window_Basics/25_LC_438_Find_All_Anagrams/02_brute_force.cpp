#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;sort(p.begin(),p.end());for(int i=0;i+p.size()<=s.size();++i){string part=s.substr(i,p.size());sort(part.begin(),part.end());if(part==p)ans.push_back(i);}return ans;
    }
};
