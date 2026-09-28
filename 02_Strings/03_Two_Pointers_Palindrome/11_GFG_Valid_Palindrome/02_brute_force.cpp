#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned;for(unsigned char c:s)if(isalnum(c))cleaned+=char(tolower(c));string backwards=cleaned;reverse(backwards.begin(),backwards.end());return cleaned==backwards;
    }
};
