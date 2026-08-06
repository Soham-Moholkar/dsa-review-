#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] != i + 1) return i + 1;
        }
        return arr.size() + 1;
    }
};

/*
Time Complexity: O(n log n)
Extra Space: O(log n)
Approach: Sort and find first mismatch.
*/
