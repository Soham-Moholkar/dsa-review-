#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        for(int row = 0; row < mat.size(); row++) {
            if(binary_search(mat[row].begin(), mat[row].end(), x)) return true;
        }
        return false;
    }
};

/*
Time Complexity: O(r log c)
Extra Space: O(1)
Approach: Binary search every row.
*/
