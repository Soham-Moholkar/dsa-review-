#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (nums[i] == 0);
        }
        int answer = 0;
        for(int left = 0; left < n; left++) {
            int low = left;
            int high = n - 1;
            int best = left - 1;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                int zeroes = prefix[mid + 1] - prefix[left];
                if(zeroes <= k) {
                    best = mid;
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            answer = max(answer, best - left + 1);
        }
        return answer;
    }
};

/*
Time Complexity: O(n log n)
Extra Space: O(n)
Approach: Prefix zero count with binary search.
*/
