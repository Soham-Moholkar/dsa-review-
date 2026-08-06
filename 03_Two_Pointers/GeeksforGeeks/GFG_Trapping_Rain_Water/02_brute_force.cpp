#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxWater(vector<int>& arr) {
        long long water = 0;
        for(int i = 0; i < arr.size(); i++) {
            int leftMaximum = arr[i];
            int rightMaximum = arr[i];
            for(int j = 0; j <= i; j++) {
                leftMaximum = max(leftMaximum, arr[j]);
            }
            for(int j = i; j < arr.size(); j++) {
                rightMaximum = max(rightMaximum, arr[j]);
            }
            water = water + min(leftMaximum, rightMaximum) - arr[i];
        }
        return water;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Find left and right maxima for every index.
*/
