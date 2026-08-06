#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> values(nums.begin(), nums.end());
        for(int value = 1; value <= nums.size() + 1; value++) {
            if(values.find(value) == values.end()) return value;
        }
        return nums.size() + 1;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(n)
Approach: Hash set.
*/
