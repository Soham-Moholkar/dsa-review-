#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int answer = INT_MIN;
        for(int start = 0; start < nums.size(); start++) {
            for(int end = start; end < nums.size(); end++) {
                int sum = 0;
                for(int i = start; i <= end; i++) {
                    sum = sum + nums[i];
                }
                answer = max(answer, sum);
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(n^3)
Extra Space: O(1)
Approach: Triple-loop enumeration.
*/
