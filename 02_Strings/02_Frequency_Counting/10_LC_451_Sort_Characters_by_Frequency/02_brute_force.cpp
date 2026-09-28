#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        map<char,int> f;for(char c:s)++f[c];vector<pair<char,int>> order(f.begin(),f.end());sort(order.begin(),order.end(),[](auto a,auto b){return a.second>b.second;});string out;for(auto [c,n]:order)out.append(n,c);return out;
    }
};
