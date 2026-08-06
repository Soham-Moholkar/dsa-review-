#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int answer = INT_MAX;
        for(int left = 0; left < n; left++) {
            long long required = prefix[left] + target;
            int right = lower_bound(prefix.begin() + left + 1, prefix.end(), required) - prefix.begin();
            if(right <= n) {
                answer = min(answer, right - left);
            }
        }
        return answer == INT_MAX ? 0 : answer;
    }
};

/*
Time Complexity: O(n log n)
Extra Space: O(n)
Approach: Prefix sums with lower_bound.
*/
