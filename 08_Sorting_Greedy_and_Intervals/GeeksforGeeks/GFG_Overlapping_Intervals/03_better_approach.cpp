#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        if(arr.empty()) return {};
        sort(arr.begin(), arr.end());
        vector<vector<int>> answer;
        answer.push_back(arr[0]);
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i][0] <= answer.back()[1]) {
                answer.back()[1] = max(answer.back()[1], arr[i][1]);
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
Extra Space: O(n)
Approach: Sort and merge into answer.
*/
