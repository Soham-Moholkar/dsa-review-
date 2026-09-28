#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        deque<int> dq;vector<int> out;for(int i=0;i<(int)arr.size();++i){if(arr[i]<0)dq.push_back(i);while(!dq.empty()&&dq.front()<=i-k)dq.pop_front();if(i>=k-1)out.push_back(dq.empty()?0:arr[dq.front()]);}return out;
    }
};
