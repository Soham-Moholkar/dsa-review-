#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int, int> getMinMax(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        return {arr[0], arr[arr.size() - 1]};
    }
};

/*
Time Complexity: O(n log n)
Extra Space: O(log n)
Approach: Sort the array.
*/
