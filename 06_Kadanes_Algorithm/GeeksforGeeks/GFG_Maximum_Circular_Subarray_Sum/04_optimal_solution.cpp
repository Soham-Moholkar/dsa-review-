#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int circularSubarraySum(vector<int>& arr) {
        int totalSum = arr[0];
        int currentMaximum = arr[0];
        int maximumSum = arr[0];
        int currentMinimum = arr[0];
        int minimumSum = arr[0];
        for(int i = 1; i < arr.size(); i++) {
            totalSum = totalSum + arr[i];
            currentMaximum = max(arr[i], currentMaximum + arr[i]);
            maximumSum = max(maximumSum, currentMaximum);
            currentMinimum = min(arr[i], currentMinimum + arr[i]);
            minimumSum = min(minimumSum, currentMinimum);
        }
        if(maximumSum < 0) {
            return maximumSum;
        }
        return max(maximumSum, totalSum - minimumSum);
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Maximum Kadane plus total minus minimum Kadane.
*/
