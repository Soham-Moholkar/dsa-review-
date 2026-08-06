#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int answer = INT_MAX;
        for(int start = 0; start < nums.size(); start++) {
            int sum = 0;
            for(int end = start; end < nums.size(); end++) {
                sum = sum + nums[end];
                if(sum >= target) {
                    answer = min(answer, end - start + 1);
                    break;
                }
            }
        }
        return answer == INT_MAX ? 0 : answer;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Try every start.
*/
