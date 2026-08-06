#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        int row = 0;
        int column = mat[0].size() - 1;
        while(row < mat.size() && column >= 0) {
            if(mat[row][column] == x) return true;
            else if(mat[row][column] > x) column--;
            else row++;
        }
        return false;
    }
};

/*
Time Complexity: O(r+c)
Extra Space: O(1)
Approach: Top-right staircase search.
*/
