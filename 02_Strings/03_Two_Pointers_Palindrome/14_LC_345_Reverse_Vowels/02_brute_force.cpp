#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        string vowels;for(char c:s)if(string("aeiouAEIOU").find(c)!=string::npos)vowels+=c;reverse(vowels.begin(),vowels.end());int i=0;for(char& c:s)if(string("aeiouAEIOU").find(c)!=string::npos)c=vowels[i++];return s;
    }
};
