#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void booleanMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        bool firstRow = false;
        bool firstColumn = false;
        for(int column = 0; column < columns; column++) if(matrix[0][column] == 1) firstRow = true;
        for(int row = 0; row < rows; row++) if(matrix[row][0] == 1) firstColumn = true;
        for(int row = 1; row < rows; row++) {
            for(int column = 1; column < columns; column++) {
                if(matrix[row][column] == 1) {
                    matrix[row][0] = 1;
                    matrix[0][column] = 1;
                }
            }
        }
        for(int row = 1; row < rows; row++) {
            for(int column = 1; column < columns; column++) {
                if(matrix[row][0] == 1 || matrix[0][column] == 1) matrix[row][column] = 1;
            }
        }
        if(firstRow) for(int column = 0; column < columns; column++) matrix[0][column] = 1;
        if(firstColumn) for(int row = 0; row < rows; row++) matrix[row][0] = 1;
    }
};

/*
Time Complexity: O(r × c)
Extra Space: O(1)
Approach: Use first row and column as markers.
*/
