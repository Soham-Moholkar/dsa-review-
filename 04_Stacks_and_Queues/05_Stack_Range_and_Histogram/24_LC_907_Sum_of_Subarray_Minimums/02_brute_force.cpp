#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int mod=1000000007;long long sum=0;for(int i=0;i<(int)arr.size();++i){int low=INT_MAX;for(int j=i;j<(int)arr.size();++j){low=min(low,arr[j]);sum=(sum+low)%mod;}}return (int)sum;
    }
};
