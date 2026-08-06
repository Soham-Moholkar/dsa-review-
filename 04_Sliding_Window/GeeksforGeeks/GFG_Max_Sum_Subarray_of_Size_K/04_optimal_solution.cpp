#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSumSubarray(int K, vector<int> &Arr, int N) {
        long long windowSum = 0;
        for(int i = 0; i < K; i++) {
            windowSum = windowSum + Arr[i];
        }
        long long answer = windowSum;
        for(int i = K; i < N; i++) {
            windowSum = windowSum + Arr[i];
            windowSum = windowSum - Arr[i - K];
            answer = max(answer, windowSum);
        }
        return answer;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Fixed sliding window.
*/
