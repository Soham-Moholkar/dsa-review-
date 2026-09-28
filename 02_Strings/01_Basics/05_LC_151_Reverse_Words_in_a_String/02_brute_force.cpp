#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        istringstream in(s);vector<string> words;string w,out;while(in>>w)words.push_back(w);for(int i=(int)words.size()-1;i>=0;--i){if(!out.empty())out+=' ';out+=words[i];}return out;
    }
};
