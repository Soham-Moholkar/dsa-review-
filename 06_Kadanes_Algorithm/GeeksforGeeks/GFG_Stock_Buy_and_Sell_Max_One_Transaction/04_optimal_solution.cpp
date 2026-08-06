#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProfit(vector<int>& prices) {
        int minimumPrice = prices[0];
        int answer = 0;
        for(int i = 1; i < prices.size(); i++) {
            answer = max(answer, prices[i] - minimumPrice);
            minimumPrice = min(minimumPrice, prices[i]);
        }
        return answer;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Minimum price seen so far.
*/
