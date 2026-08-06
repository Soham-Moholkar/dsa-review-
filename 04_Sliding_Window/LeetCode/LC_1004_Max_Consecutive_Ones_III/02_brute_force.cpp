#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int answer = 0;
        for(int start = 0; start < nums.size(); start++) {
            int zeroes = 0;
            for(int end = start; end < nums.size(); end++) {
                if(nums[end] == 0) {
                    zeroes++;
                }
                if(zeroes <= k) {
                    answer = max(answer, end - start + 1);
                }
                else {
                    break;
                }
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Check every subarray.
*/
