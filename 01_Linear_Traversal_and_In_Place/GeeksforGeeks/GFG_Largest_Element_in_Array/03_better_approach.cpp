#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largest(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        return arr[arr.size() - 1];
    }
};

/*
Time Complexity: O(n log n)
Extra Space: O(log n)
Approach: Sort and take the last value.
This changes the input order.
*/
