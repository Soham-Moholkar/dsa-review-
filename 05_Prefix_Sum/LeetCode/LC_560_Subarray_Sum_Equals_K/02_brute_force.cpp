#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int answer = 0;
        for(int start = 0; start < nums.size(); start++) {
            int sum = 0;
            for(int end = start; end < nums.size(); end++) {
                sum = sum + nums[end];
                if(sum == k) {
                    answer++;
                }
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Enumerate all subarrays.
*/
