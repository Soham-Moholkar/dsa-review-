#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int prefixProduct = 1;
        int suffixProduct = 1;
        int answer = INT_MIN;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            if(prefixProduct == 0) {
                prefixProduct = 1;
            }
            if(suffixProduct == 0) {
                suffixProduct = 1;
            }
            prefixProduct = prefixProduct * arr[i];
            suffixProduct = suffixProduct * arr[n - i - 1];
            answer = max(answer, max(prefixProduct, suffixProduct));
        }
        return answer;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Prefix and suffix product scans.
*/
