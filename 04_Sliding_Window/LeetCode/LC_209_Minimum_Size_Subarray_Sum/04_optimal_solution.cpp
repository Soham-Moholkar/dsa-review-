#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int answer = INT_MAX;
        for(int right = 0; right < nums.size(); right++) {
            sum = sum + nums[right];
            while(sum >= target) {
                answer = min(answer, right - left + 1);
                sum = sum - nums[left];
                left++;
            }
        }
        return answer == INT_MAX ? 0 : answer;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Variable sliding window.
*/
