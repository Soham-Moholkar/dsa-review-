#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> previousGreater(vector<int>& nums) {
        vector<int> ans(nums.size(),-1);stack<int> st;for(int i=0;i<(int)nums.size();++i){while(!st.empty()&&st.top()<=nums[i])st.pop();if(!st.empty())ans[i]=st.top();st.push(nums[i]);}return ans;
    }
};
