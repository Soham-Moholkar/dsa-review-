#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int i = 0; i < nums.size(); i++) {
            if(seen.find(nums[i]) != seen.end()) return nums[i];
            seen.insert(nums[i]);
        }
        return -1;
    }
};

/*
Time Complexity: O(n) average
Extra Space: O(n)
Approach: Hash set.
*/
