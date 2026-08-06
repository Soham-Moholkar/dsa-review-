#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result = intervals;
        bool changed = true;
        while(changed) {
            changed = false;
            for(int i = 0; i < result.size() && !changed; i++) {
                for(int j = i + 1; j < result.size(); j++) {
                    if(max(result[i][0], result[j][0]) <= min(result[i][1], result[j][1])) {
                        result[i] = {min(result[i][0], result[j][0]), max(result[i][1], result[j][1])};
                        result.erase(result.begin() + j);
                        changed = true;
                        break;
                    }
                }
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};

/*
Time Complexity: O(n^3)
Extra Space: O(n)
Approach: Repeated pair merging.
*/
