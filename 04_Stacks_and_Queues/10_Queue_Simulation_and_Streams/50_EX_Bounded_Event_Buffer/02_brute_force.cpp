#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lastEvents(vector<int>& events, int capacity) {
        if(capacity==0)return {};int begin=max(0,(int)events.size()-capacity);return vector<int>(events.begin()+begin,events.end());
    }
};
