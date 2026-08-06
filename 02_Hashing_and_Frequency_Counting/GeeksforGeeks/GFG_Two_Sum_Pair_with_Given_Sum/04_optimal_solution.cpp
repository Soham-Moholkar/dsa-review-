#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool twoSum(vector<int>& arr, int target) {
        unordered_set<int> seen;
        for(int i = 0; i < arr.size(); i++) {
            int remaining = target - arr[i];
            if(seen.find(remaining) != seen.end()) {
                return true;
            }
            seen.insert(arr[i]);
        }
        return false;
    }
};

/*
Time Complexity: O(n) average
Extra Space: O(n)
Approach: Hash-set complement lookup.
*/
