#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        for(int length=(int)s.size()-1;length>0;--length)if(s.compare(0,length,s,s.size()-length,length)==0)return s.substr(0,length);return "";
    }
};
