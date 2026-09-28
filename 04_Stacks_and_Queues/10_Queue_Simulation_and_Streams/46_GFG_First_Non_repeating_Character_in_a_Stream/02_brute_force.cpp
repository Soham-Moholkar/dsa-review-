#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string FirstNonRepeating(string s) {
        int freq[256]={};queue<char> q;string out;for(char c:s){++freq[(unsigned char)c];q.push(c);while(!q.empty()&&freq[(unsigned char)q.front()]>1)q.pop();out+=q.empty()?'#':q.front();}return out;
    }
};
