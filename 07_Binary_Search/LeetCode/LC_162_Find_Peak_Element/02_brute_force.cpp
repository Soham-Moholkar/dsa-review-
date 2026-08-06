#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            bool leftOkay = i == 0 || nums[i] > nums[i - 1];
            bool rightOkay = i == nums.size() - 1 || nums[i] > nums[i + 1];
            if(leftOkay && rightOkay) return i;
        }
        return -1;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Neighbour checks.
*/
