#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProfit(vector<int>& prices) {
        int answer = 0;
        for(int buy = 0; buy < prices.size(); buy++) {
            for(int sell = buy + 1; sell < prices.size(); sell++) {
                answer = max(answer, prices[sell] - prices[buy]);
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Try every buy and sell pair.
*/
