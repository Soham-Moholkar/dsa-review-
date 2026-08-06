#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSumSubarray(int K, vector<int> &Arr, int N) {
        long long answer = LLONG_MIN;
        for(int start = 0; start + K <= N; start++) {
            long long sum = 0;
            for(int i = start; i < start + K; i++) {
                sum = sum + Arr[i];
            }
            answer = max(answer, sum);
        }
        return answer;
    }
};

/*
Time Complexity: O(n × k)
Extra Space: O(1)
Approach: Recalculate every window.
*/
