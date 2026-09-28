#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string out; int i=(int)s.size()-1; while(i>=0){while(i>=0&&s[i]==' ') --i; if(i<0) break; int end=i; while(i>=0&&s[i]!=' ') --i; if(!out.empty()) out+=' '; out+=s.substr(i+1,end-i);} return out;
    }
};
