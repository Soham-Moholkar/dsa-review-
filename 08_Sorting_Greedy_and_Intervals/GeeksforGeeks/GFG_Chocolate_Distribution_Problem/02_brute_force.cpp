#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinDiff(vector<int>& a, int m) {
        int n = a.size();
        int answer = INT_MAX;
        vector<int> chosen;
        function<void(int)> solve = [&](int index) {
            if(chosen.size() == m) {
                int minimumValue = *min_element(chosen.begin(), chosen.end());
                int maximumValue = *max_element(chosen.begin(), chosen.end());
                answer = min(answer, maximumValue - minimumValue);
                return;
            }
            if(index == n) return;
            chosen.push_back(a[index]);
            solve(index + 1);
            chosen.pop_back();
            solve(index + 1);
        };
        solve(0);
        return answer;
    }
};

/*
Time Complexity: Exponential
Extra Space: O(m)
Approach: Enumerate subsets recursively.
*/
