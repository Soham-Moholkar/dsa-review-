#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& arr) {
        long long currentSum = arr[0];
        long long maximumSum = arr[0];
        for(int i = 1; i < arr.size(); i++) {
            currentSum = max((long long)arr[i], currentSum + arr[i]);
            maximumSum = max(maximumSum, currentSum);
        }
        return maximumSum;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Kadane state transition.
*/
