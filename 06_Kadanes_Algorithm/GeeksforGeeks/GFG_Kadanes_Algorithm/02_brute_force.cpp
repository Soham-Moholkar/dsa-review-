#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& arr) {
        long long answer = LLONG_MIN;
        for(int start = 0; start < arr.size(); start++) {
            for(int end = start; end < arr.size(); end++) {
                long long sum = 0;
                for(int i = start; i <= end; i++) {
                    sum = sum + arr[i];
                }
                answer = max(answer, sum);
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(n^3)
Extra Space: O(1)
Approach: Generate every subarray and rescan it.
*/
