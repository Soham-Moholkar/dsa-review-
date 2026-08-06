#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> find(vector<int>& arr, int x) {
        int first = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        if(first == arr.size() || arr[first] != x) {
            return {-1, -1};
        }
        int last = upper_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;
        return {first, last};
    }
};

/*
Time Complexity: O(log n)
Extra Space: O(1)
Approach: lower_bound and upper_bound.
*/
