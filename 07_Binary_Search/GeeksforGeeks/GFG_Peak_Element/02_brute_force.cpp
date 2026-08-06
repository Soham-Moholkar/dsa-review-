#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakElement(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            bool leftOkay = i == 0 || arr[i] >= arr[i - 1];
            bool rightOkay = i == n - 1 || arr[i] >= arr[i + 1];
            if(leftOkay && rightOkay) {
                return i;
            }
        }
        return -1;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Check every index and both neighbours.
*/
