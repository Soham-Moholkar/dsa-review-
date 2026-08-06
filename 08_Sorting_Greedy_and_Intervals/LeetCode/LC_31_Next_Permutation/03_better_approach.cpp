#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Use the standard library operation.
*/
