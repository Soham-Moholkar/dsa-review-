#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maximumCount = 0;
        for(int i = 0; i < nums.size(); i++) {
            int currentCount = 0;
            for(int j = i; j < nums.size(); j++) {
                if(nums[j] == 1) {
                    currentCount++;
                    maximumCount = max(maximumCount, currentCount);
                }
                else {
                    break;
                }
            }
        }
        return maximumCount;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Start a streak from every index.
*/
