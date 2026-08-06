#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int leftSum = 0;
            int rightSum = 0;
            for(int j = 0; j < i; j++) {
                leftSum = leftSum + nums[j];
            }
            for(int j = i + 1; j < nums.size(); j++) {
                rightSum = rightSum + nums[j];
            }
            if(leftSum == rightSum) {
                return i;
            }
        }
        return -1;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Recalculate both sides.
*/
