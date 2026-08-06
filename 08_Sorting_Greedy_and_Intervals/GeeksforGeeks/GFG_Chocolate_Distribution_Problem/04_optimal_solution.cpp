#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinDiff(vector<int>& a, int m) {
        if(m == 0 || a.size() < m) {
            return 0;
        }
        sort(a.begin(), a.end());
        int minimumDifference = INT_MAX;
        for(int right = m - 1; right < a.size(); right++) {
            int left = right - m + 1;
            minimumDifference = min(minimumDifference, a[right] - a[left]);
        }
        return minimumDifference;
    }
};

/*
Time Complexity: O(n log n)
Extra Space: O(log n)
Approach: Sorted fixed-size greedy window.
*/
