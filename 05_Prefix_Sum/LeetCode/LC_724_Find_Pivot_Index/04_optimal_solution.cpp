#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            totalSum = totalSum + nums[i];
        }
        int leftSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            totalSum = totalSum - nums[i];
            if(leftSum == totalSum) {
                return i;
            }
            leftSum = leftSum + nums[i];
        }
        return -1;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Total sum and left sum.
*/
