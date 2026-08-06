#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimumPrice = prices[0];
        int maximumProfit = 0;
        for(int i = 1; i < prices.size(); i++) {
            maximumProfit = max(maximumProfit, prices[i] - minimumPrice);
            minimumPrice = min(minimumPrice, prices[i]);
        }
        return maximumProfit;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Minimum-so-far scan.
*/
