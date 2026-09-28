#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const long long MOD=1000000007;int n=arr.size();vector<int> left(n),right(n),st;for(int i=0;i<n;++i){while(!st.empty()&&arr[st.back()]>=arr[i])st.pop_back();left[i]=st.empty()?-1:st.back();st.push_back(i);}st.clear();for(int i=n-1;i>=0;--i){while(!st.empty()&&arr[st.back()]>arr[i])st.pop_back();right[i]=st.empty()?n:st.back();st.push_back(i);}long long total=0;for(int i=0;i<n;++i)total=(total+(long long)arr[i]*(i-left[i])*(right[i]-i))%MOD;return (int)total;
    }
};
