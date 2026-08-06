#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> values(nums.begin(), nums.end());
        int j = 0;
        for(auto value : values) {
            nums[j] = value;
            j++;
        }
        return j;
    }
};

/*
Time Complexity: O(n log n)
Extra Space: O(n)
Approach: Use a set.
*/
