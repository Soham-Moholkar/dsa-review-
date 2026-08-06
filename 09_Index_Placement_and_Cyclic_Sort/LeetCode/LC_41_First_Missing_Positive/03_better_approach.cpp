#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int required = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == required) required++;
        }
        return required;
    }
};

/*
Time Complexity: O(n log n)
Extra Space: O(log n)
Approach: Sort and scan.
*/
