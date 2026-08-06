#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSumSubarray(int K, vector<int> &Arr, int N) {
        vector<long long> prefix(N + 1, 0);
        for(int i = 0; i < N; i++) {
            prefix[i + 1] = prefix[i] + Arr[i];
        }
        long long answer = LLONG_MIN;
        for(int right = K; right <= N; right++) {
            long long sum = prefix[right] - prefix[right - K];
            answer = max(answer, sum);
        }
        return answer;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(n)
Approach: Prefix sums.
*/
