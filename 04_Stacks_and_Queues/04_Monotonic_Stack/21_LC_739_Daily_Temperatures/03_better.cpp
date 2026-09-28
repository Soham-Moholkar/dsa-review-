#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();vector<int> ans(n),st;for(int i=0;i<n;++i){while(!st.empty()&&temperatures[i]>temperatures[st.back()]){int j=st.back();st.pop_back();ans[j]=i-j;}st.push_back(i);}return ans;
    }
};
