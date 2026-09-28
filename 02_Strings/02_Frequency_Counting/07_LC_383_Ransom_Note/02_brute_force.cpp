#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for(char c:ransomNote){auto pos=magazine.find(c);if(pos==string::npos)return false;magazine.erase(pos,1);}return true;
    }
};
