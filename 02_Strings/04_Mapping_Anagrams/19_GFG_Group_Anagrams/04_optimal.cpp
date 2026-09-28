#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> groups; for(const string& s:strs){string key=s;sort(key.begin(),key.end());groups[key].push_back(s);} vector<vector<string>> out;for(auto& [key,values]:groups) out.push_back(values);return out;
    }
};
