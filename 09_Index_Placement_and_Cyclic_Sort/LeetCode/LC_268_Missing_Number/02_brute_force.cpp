#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(int value = 0; value <= nums.size(); value++) {
            bool found = false;
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] == value) found = true;
            }
            if(!found) return value;
        }
        return -1;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Test every candidate.
*/
