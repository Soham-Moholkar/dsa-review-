#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> answer;
        if(intervals.size() == 0) return answer;
        sort(intervals.begin(), intervals.end());
        answer.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] <= answer.back()[1]) {
                answer.back()[1] = max(answer.back()[1], intervals[i][1]);
            }
            else {
                answer.push_back(intervals[i]);
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(n log n)
Extra Space: O(n) answer
Approach: One sorted pass.
*/
