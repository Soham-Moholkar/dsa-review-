#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int zeroes = 0;
        int answer = 0;
        for(int right = 0; right < nums.size(); right++) {
            if(nums[right] == 0) {
                zeroes++;
            }
            while(zeroes > k) {
                if(nums[left] == 0) {
                    zeroes--;
                }
                left++;
            }
            answer = max(answer, right - left + 1);
        }
        return answer;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Variable sliding window.
*/
