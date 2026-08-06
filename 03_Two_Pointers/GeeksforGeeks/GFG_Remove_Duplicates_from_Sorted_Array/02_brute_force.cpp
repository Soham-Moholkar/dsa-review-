#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        set<int> values(arr.begin(), arr.end());
        int j = 0;
        for(auto value : values) {
            arr[j] = value;
            j++;
        }
        return j;
    }
};

/*
Time Complexity: O(n log n)
Extra Space: O(n)
Approach: Use an ordered set and copy back.
*/
