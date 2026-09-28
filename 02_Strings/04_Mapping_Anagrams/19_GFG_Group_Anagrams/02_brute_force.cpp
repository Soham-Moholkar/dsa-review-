#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;for(auto& s:strs){string key=s;sort(key.begin(),key.end());bool found=false;for(auto& group:groups){string other=group[0];sort(other.begin(),other.end());if(other==key){group.push_back(s);found=true;break;}}if(!found)groups.push_back({s});}return groups;
    }
};
