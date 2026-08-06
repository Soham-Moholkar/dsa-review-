#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> answer(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j <= i; j++) {
                answer[i] = answer[i] + nums[j];
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(n)
Approach: Recalculate each prefix.
*/
