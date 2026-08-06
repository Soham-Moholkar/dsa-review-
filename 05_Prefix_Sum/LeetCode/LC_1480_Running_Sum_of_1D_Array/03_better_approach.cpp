#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> answer(nums.size());
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
            answer[i] = sum;
        }
        return answer;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(n)
Approach: Build a separate running result.
*/
