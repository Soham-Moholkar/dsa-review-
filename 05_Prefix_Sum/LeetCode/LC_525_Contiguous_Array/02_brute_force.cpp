#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int answer = 0;
        for(int start = 0; start < nums.size(); start++) {
            int zeroes = 0;
            int ones = 0;
            for(int end = start; end < nums.size(); end++) {
                if(nums[end] == 0) {
                    zeroes++;
                }
                else {
                    ones++;
                }
                if(zeroes == ones) {
                    answer = max(answer, end - start + 1);
                }
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Count zeroes and ones for every subarray.
*/
