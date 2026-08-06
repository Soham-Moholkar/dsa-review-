#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getSecondLargest(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        int largestValue = arr[arr.size() - 1];
        for(int i = arr.size() - 2; i >= 0; i--) {
            if(arr[i] != largestValue) {
                return arr[i];
            }
        }
        return -1;
    }
};

/*
Time Complexity: O(n log n)
Extra Space: O(log n)
Approach: Sort and locate the first distinct value.
*/
