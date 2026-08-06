#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equilibriumPoint(vector<int>& arr) {
        int n = arr.size();
        vector<long long> prefix(n, 0);
        vector<long long> suffix(n, 0);
        prefix[0] = arr[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        suffix[n - 1] = arr[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + arr[i];
        }
        for(int i = 0; i < n; i++) {
            long long leftSum = i == 0 ? 0 : prefix[i - 1];
            long long rightSum = i == n - 1 ? 0 : suffix[i + 1];
            if(leftSum == rightSum) {
                return i + 1;
            }
        }
        return -1;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(n)
Approach: Prefix and suffix arrays.
*/
