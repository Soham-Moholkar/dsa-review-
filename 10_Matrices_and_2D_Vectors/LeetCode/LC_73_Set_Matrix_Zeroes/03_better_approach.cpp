#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        vector<bool> zeroRow(rows, false);
        vector<bool> zeroColumn(columns, false);
        for(int row = 0; row < rows; row++) {
            for(int column = 0; column < columns; column++) {
                if(matrix[row][column] == 0) {
                    zeroRow[row] = true;
                    zeroColumn[column] = true;
                }
            }
        }
        for(int row = 0; row < rows; row++) {
            for(int column = 0; column < columns; column++) {
                if(zeroRow[row] || zeroColumn[column]) matrix[row][column] = 0;
            }
        }
    }
};

/*
Time Complexity: O(r × c)
Extra Space: O(r+c)
Approach: Row and column marker arrays.
*/
