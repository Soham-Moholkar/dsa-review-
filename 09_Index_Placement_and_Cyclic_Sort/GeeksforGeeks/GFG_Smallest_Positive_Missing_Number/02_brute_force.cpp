#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        unordered_set<int> values(arr.begin(), arr.end());
        for(int value = 1; value <= arr.size() + 1; value++) {
            if(values.find(value) == values.end()) return value;
        }
        return arr.size() + 1;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(n)
Approach: Store values in a set and scan positives.
*/
