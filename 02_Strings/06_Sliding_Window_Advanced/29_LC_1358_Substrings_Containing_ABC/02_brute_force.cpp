#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;for(int i=0;i<(int)s.size();++i){bool seen[3]={};for(int j=i;j<(int)s.size();++j){seen[s[j]-'a']=true;if(seen[0]&&seen[1]&&seen[2])++ans;}}return ans;
    }
};
