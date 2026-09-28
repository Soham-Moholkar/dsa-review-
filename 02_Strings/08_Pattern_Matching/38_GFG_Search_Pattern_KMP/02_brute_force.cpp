#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> search(string &pat, string &txt) {
        vector<int> ans;for(int i=0;i+pat.size()<=txt.size();++i)if(txt.compare(i,pat.size(),pat)==0)ans.push_back(i);return ans;
    }
};
