#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        vector<int> count;vector<string> previous;string part;int value=0;for(char c:s){if(isdigit((unsigned char)c))value=value*10+c-'0';else if(c=='['){count.push_back(value);previous.push_back(part);value=0;part.clear();}else if(c==']'){string block=part;part=previous.back();previous.pop_back();int n=count.back();count.pop_back();while(n--)part+=block;}else part+=c;}return part;
    }
};
