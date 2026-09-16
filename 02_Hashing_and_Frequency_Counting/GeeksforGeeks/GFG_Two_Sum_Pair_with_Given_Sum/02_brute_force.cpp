#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool twoSum(vector<int>& arr, int target) {
        for(int i = 0; i < arr.size(); i++) {
            for(int j = i + 1; j < arr.size(); j++) {
                if(1LL * arr[i] + arr[j] == target) {
                    return true;
                }
            }
        }
        return false;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Compare every pair.
*/
