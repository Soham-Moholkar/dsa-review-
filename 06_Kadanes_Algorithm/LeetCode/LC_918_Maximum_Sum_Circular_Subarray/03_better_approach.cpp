#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> doubled = nums;
        doubled.insert(doubled.end(), nums.begin(), nums.end());
        int answer = INT_MIN;
        for(int start = 0; start < n; start++) {
            int sum = 0;
            for(int end = start; end < start + n; end++) {
                sum = sum + doubled[end];
                answer = max(answer, sum);
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(n)
Approach: Duplicate and enumerate bounded ranges.
*/
