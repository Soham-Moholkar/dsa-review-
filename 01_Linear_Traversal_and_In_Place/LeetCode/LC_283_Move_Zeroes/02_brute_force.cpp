#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> answer;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                answer.push_back(nums[i]);
            }
        }
        while(answer.size() < nums.size()) {
            answer.push_back(0);
        }
        nums = answer;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(n)
Approach: Use an additional result vector.
*/
