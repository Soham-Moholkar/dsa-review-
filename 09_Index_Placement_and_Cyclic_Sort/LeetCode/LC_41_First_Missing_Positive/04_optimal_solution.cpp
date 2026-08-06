#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < n) {
            int correctIndex = nums[i] - 1;
            if(nums[i] >= 1 && nums[i] <= n && nums[i] != nums[correctIndex]) {
                swap(nums[i], nums[correctIndex]);
            }
            else {
                i++;
            }
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Cyclic placement.
*/
