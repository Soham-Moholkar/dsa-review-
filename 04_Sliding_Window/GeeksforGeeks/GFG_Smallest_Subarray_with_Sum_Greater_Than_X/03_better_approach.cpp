#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        int n = arr.size();
        vector<long long> prefix(n + 1, 0);
        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }
        int answer = INT_MAX;
        for(int left = 0; left < n; left++) {
            long long required = prefix[left] + x + 1;
            int rightPrefix = lower_bound(prefix.begin() + left + 1, prefix.end(), required) - prefix.begin();
            if(rightPrefix <= n) {
                answer = min(answer, rightPrefix - left);
            }
        }
        return answer == INT_MAX ? 0 : answer;
    }
};

/*
Time Complexity: O(n log n)
Extra Space: O(n)
Approach: Prefix sums with binary search.
*/
