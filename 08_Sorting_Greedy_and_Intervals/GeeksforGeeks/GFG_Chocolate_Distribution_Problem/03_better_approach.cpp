#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinDiff(vector<int>& a, int m) {
        if(m == 0 || a.size() < m) return 0;
        sort(a.begin(), a.end());
        int answer = INT_MAX;
        for(int i = 0; i + m <= a.size(); i++) {
            answer = min(answer, a[i + m - 1] - a[i]);
        }
        return answer;
    }
};

/*
Time Complexity: O(n log n)
Extra Space: O(log n)
Approach: Sort and test all m-sized windows.
*/
