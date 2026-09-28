#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int opens=0,add=0;for(char c:s){if(c=='(')++opens;else if(opens)--opens;else ++add;}return add+opens;
    }
};
