#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& arr) {
        long long answer = LLONG_MIN;
        for(int start = 0; start < arr.size(); start++) {
            long long sum = 0;
            for(int end = start; end < arr.size(); end++) {
                sum = sum + arr[end];
                answer = max(answer, sum);
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Running sum for every start.
*/
