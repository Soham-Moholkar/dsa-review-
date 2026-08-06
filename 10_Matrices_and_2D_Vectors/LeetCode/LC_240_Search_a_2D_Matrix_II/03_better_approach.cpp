#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int row = 0; row < matrix.size(); row++) {
            if(binary_search(matrix[row].begin(), matrix[row].end(), target)) return true;
        }
        return false;
    }
};

/*
Time Complexity: O(r log c)
Extra Space: O(1)
Approach: Binary search each row.
*/
