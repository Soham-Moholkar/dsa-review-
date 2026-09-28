#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        int cnt[256]={}; for(unsigned char c:s) ++cnt[c]; vector<pair<int,char>> items; for(int c=0;c<256;++c) if(cnt[c]) items.push_back({cnt[c],char(c)}); sort(items.begin(),items.end(),[](auto a,auto b){return a.first>b.first;}); string out; for(auto [n,c]:items) out.append(n,c); return out;
    }
};
