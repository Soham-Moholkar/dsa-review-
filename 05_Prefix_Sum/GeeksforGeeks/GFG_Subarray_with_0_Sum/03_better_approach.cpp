#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool subArrayExists(vector<int>& arr) {
        vector<long long> prefix;
        long long sum = 0;
        prefix.push_back(0);
        for(int i = 0; i < arr.size(); i++) {
            sum = sum + arr[i];
            prefix.push_back(sum);
        }
        sort(prefix.begin(), prefix.end());
        for(int i = 1; i < prefix.size(); i++) {
            if(prefix[i] == prefix[i - 1]) {
                return true;
            }
        }
        return false;
    }
};

/*
Time Complexity: O(n log n)
Extra Space: O(n)
Approach: Store, sort, and compare prefix sums.
*/
