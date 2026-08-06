#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        int repeating = -1;
        int missing = -1;
        int n = arr.size();
        for(int value = 1; value <= n; value++) {
            int count = 0;
            for(int i = 0; i < n; i++) {
                if(arr[i] == value) count++;
            }
            if(count == 0) missing = value;
            if(count == 2) repeating = value;
        }
        return {repeating, missing};
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Count every possible value.
*/
