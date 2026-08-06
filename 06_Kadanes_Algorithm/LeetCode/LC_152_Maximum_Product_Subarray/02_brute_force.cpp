#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int answer = INT_MIN;
        for(int start = 0; start < nums.size(); start++) {
            int product = 1;
            for(int end = start; end < nums.size(); end++) {
                product = product * nums[end];
                answer = max(answer, product);
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Enumerate every product.
*/
