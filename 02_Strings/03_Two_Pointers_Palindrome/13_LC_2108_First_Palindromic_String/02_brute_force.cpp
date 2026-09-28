#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(const string& w:words){bool ok=true; for(int i=0,j=(int)w.size()-1;i<j;++i,--j) if(w[i]!=w[j]){ok=false;break;} if(ok) return w;} return "";
    }
};
