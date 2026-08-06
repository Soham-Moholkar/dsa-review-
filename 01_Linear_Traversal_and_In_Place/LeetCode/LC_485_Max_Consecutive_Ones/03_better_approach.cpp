#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currentCount = 0;
        int maximumCount = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                currentCount++;
            }
            else {
                currentCount = 0;
            }
            maximumCount = max(maximumCount, currentCount);
        }
        return maximumCount;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Single scan with explicit reset.
*/
