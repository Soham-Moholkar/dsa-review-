#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void booleanMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        vector<bool> markRow(rows, false);
        vector<bool> markColumn(columns, false);
        for(int row = 0; row < rows; row++) {
            for(int column = 0; column < columns; column++) {
                if(matrix[row][column] == 1) {
                    markRow[row] = true;
                    markColumn[column] = true;
                }
            }
        }
        for(int row = 0; row < rows; row++) {
            for(int column = 0; column < columns; column++) {
                if(markRow[row] || markColumn[column]) matrix[row][column] = 1;
            }
        }
    }
};

/*
Time Complexity: O(r × c)
Extra Space: O(r+c)
Approach: Row and column marker arrays.
*/
