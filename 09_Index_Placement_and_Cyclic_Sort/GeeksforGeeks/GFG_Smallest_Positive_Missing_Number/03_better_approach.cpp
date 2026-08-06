#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int required = 1;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == required) required++;
        }
        return required;
    }
};

/*
Time Complexity: O(n log n)
Extra Space: O(log n)
Approach: Sort and scan.
*/
