#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefixProduct = 1;
        int suffixProduct = 1;
        int answer = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(prefixProduct == 0) prefixProduct = 1;
            if(suffixProduct == 0) suffixProduct = 1;
            prefixProduct = prefixProduct * nums[i];
            suffixProduct = suffixProduct * nums[n - i - 1];
            answer = max(answer, max(prefixProduct, suffixProduct));
        }
        return answer;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Bidirectional product scans.
*/
