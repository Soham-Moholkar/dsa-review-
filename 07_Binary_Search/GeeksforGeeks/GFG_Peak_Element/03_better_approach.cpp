#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakElement(vector<int>& arr) {
        for(int i = 0; i + 1 < arr.size(); i++) {
            if(arr[i] >= arr[i + 1]) {
                return i;
            }
        }
        return arr.size() - 1;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Linear slope scan.
*/
