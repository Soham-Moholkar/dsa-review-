#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for(int i = 0; i + 1 < nums.size(); i++) {
            if(nums[i] > nums[i + 1]) return i;
        }
        return nums.size() - 1;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: First falling edge.
*/
