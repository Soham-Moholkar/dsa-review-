#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        string letters;for(char c:s)if(isalpha((unsigned char)c))letters+=c;reverse(letters.begin(),letters.end());int i=0;for(char& c:s)if(isalpha((unsigned char)c))c=letters[i++];return s;
    }
};
