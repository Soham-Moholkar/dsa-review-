#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen,dup;for(int i=0;i+10<=(int)s.size();++i){string part=s.substr(i,10);if(!seen.insert(part).second)dup.insert(part);}return vector<string>(dup.begin(),dup.end());
    }
};
