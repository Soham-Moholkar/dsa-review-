#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        vector<long long> prefix(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        long long maximumSum = LLONG_MIN;
        for(int right = k; right <= nums.size(); right++) {
            maximumSum = max(maximumSum, prefix[right] - prefix[right - k]);
        }
        return (double)maximumSum / k;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(n)
Approach: Prefix sums.
*/
