#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size() + 1;
        for(int value = 1; value <= n; value++) {
            bool found = false;
            for(int i = 0; i < arr.size(); i++) {
                if(arr[i] == value) {
                    found = true;
                    break;
                }
            }
            if(!found) return value;
        }
        return -1;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Test every candidate.
*/
