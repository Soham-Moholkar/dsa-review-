#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream in(s);string word,last;while(in>>word)last=word;return last.size();
    }
};
