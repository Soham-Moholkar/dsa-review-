#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxWater(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) {
            return 0;
        }
        vector<int> leftMaximum(n);
        vector<int> rightMaximum(n);
        leftMaximum[0] = arr[0];
        for(int i = 1; i < n; i++) {
            leftMaximum[i] = max(leftMaximum[i - 1], arr[i]);
        }
        rightMaximum[n - 1] = arr[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            rightMaximum[i] = max(rightMaximum[i + 1], arr[i]);
        }
        long long water = 0;
        for(int i = 0; i < n; i++) {
            water = water + min(leftMaximum[i], rightMaximum[i]) - arr[i];
        }
        return water;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(n)
Approach: Prefix and suffix maximum arrays.
*/
