#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        vector<vector<int>> intervals = arr;
        bool changed = true;
        while(changed) {
            changed = false;
            for(int i = 0; i < intervals.size() && !changed; i++) {
                for(int j = i + 1; j < intervals.size(); j++) {
                    if(max(intervals[i][0], intervals[j][0]) <= min(intervals[i][1], intervals[j][1])) {
                        intervals[i][0] = min(intervals[i][0], intervals[j][0]);
                        intervals[i][1] = max(intervals[i][1], intervals[j][1]);
                        intervals.erase(intervals.begin() + j);
                        changed = true;
                        break;
                    }
                }
            }
        }
        sort(intervals.begin(), intervals.end());
        return intervals;
    }
};

/*
Time Complexity: O(n^3)
Extra Space: O(n)
Approach: Repeatedly merge any overlapping pair.
*/
