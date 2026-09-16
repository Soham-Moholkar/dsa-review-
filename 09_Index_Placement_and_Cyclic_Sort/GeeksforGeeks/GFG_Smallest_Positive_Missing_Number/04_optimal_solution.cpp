#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        while(i < n) {
            // Validate the value before subtraction and indexing.
            if(arr[i] >= 1 && arr[i] <= n && arr[i] != arr[arr[i] - 1]) {
                swap(arr[i], arr[arr[i] - 1]);
            }
            else {
                i++;
            }
        }
        for(int i = 0; i < n; i++) {
            if(arr[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Cyclic placement.
*/
