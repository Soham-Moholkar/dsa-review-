#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        vector<vector<int>> answer;
        if(arr.size() == 0) return answer;
        sort(arr.begin(), arr.end());
        answer.push_back(arr[0]);
        for(int i = 1; i < arr.size(); i++) {
            int currentStart = arr[i][0];
            int currentEnd = arr[i][1];
            if(currentStart <= answer.back()[1]) {
                answer.back()[1] = max(answer.back()[1], currentEnd);
            }
            else {
                answer.push_back(arr[i]);
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(n log n)
Extra Space: O(n) answer
Approach: Sorted one-pass interval merge.
*/
