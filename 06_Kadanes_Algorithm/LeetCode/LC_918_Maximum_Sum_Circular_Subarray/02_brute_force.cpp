#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int answer = INT_MIN;
        for(int start = 0; start < n; start++) {
            int sum = 0;
            for(int length = 1; length <= n; length++) {
                sum = sum + nums[(start + length - 1) % n];
                answer = max(answer, sum);
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Enumerate circular starts and lengths.
*/
