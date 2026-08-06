#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i) return i;
        }
        return nums.size();
    }
};

/*
Time Complexity: O(n log n)
Extra Space: O(log n)
Approach: Sort and compare index to value.
*/
