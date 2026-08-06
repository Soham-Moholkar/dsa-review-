#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int answer = INT_MIN;
        for(int start = 0; start < nums.size(); start++) {
            int sum = 0;
            for(int end = start; end < nums.size(); end++) {
                sum = sum + nums[end];
                answer = max(answer, sum);
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Running sum per start.
*/
