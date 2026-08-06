#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> answer;
        for(int i = 0; i < intervals.size(); i++) {
            if(answer.empty() || intervals[i][0] > answer.back()[1]) answer.push_back(intervals[i]);
            else answer.back()[1] = max(answer.back()[1], intervals[i][1]);
        }
        return answer;
    }
};

/*
Time Complexity: O(n log n)
Extra Space: O(n)
Approach: Append, sort, merge.
*/
