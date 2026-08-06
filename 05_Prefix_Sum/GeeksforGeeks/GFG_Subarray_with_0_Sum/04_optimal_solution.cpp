#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool subArrayExists(vector<int>& arr) {
        unordered_set<long long> seen;
        seen.insert(0);
        long long prefixSum = 0;
        for(int i = 0; i < arr.size(); i++) {
            prefixSum = prefixSum + arr[i];
            if(seen.find(prefixSum) != seen.end()) {
                return true;
            }
            seen.insert(prefixSum);
        }
        return false;
    }
};

/*
Time Complexity: O(n) average
Extra Space: O(n)
Approach: Prefix sum hash set.
*/
