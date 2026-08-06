#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> suffixMaximum(n);
        suffixMaximum[n - 1] = prices[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suffixMaximum[i] = max(suffixMaximum[i + 1], prices[i]);
        }
        int answer = 0;
        for(int i = 0; i < n; i++) {
            answer = max(answer, suffixMaximum[i] - prices[i]);
        }
        return answer;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(n)
Approach: Suffix maximum prices.
*/
