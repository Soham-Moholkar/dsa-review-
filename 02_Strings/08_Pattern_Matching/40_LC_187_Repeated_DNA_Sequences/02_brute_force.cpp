#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> out;for(int i=0;i+10<=s.size();++i){string sub=s.substr(i,10);if(find(out.begin(),out.end(),sub)!=out.end())continue;for(int j=i+1;j+10<=s.size();++j)if(s.substr(j,10)==sub){out.push_back(sub);break;}}return out;
    }
};
