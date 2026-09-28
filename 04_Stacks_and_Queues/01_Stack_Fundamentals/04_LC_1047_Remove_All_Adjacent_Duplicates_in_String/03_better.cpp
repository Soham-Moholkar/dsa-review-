#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string out;for(char c:s){if(!out.empty()&&out.back()==c)out.pop_back();else out+=c;}return out;
    }
};
