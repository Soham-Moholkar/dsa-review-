#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lastEvents(vector<int>& events, int capacity) {
        vector<int> out;for(int x:events){if(capacity<=0)continue;if((int)out.size()==capacity)out.erase(out.begin());out.push_back(x);}return out;
    }
};
