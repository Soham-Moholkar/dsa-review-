#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binarysearch(vector<int> &arr, int k) {
        auto position = lower_bound(arr.begin(), arr.end(), k);
        if(position != arr.end() && *position == k) {
            return position - arr.begin();
        }
        return -1;
    }
};

/*
Time Complexity: O(log n)
Extra Space: O(1)
Approach: Standard lower_bound lookup.
*/
