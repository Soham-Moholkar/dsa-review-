#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int currentLength = 1;
        int answer = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1]) {
                continue;
            }
            if(nums[i] == nums[i - 1] + 1) {
                currentLength++;
            }
            else {
                currentLength = 1;
            }
            answer = max(answer, currentLength);
        }
        return answer;
    }
};

/*
Time Complexity: O(n log n)
Extra Space: O(log n)
Approach: Sort and scan.
*/
