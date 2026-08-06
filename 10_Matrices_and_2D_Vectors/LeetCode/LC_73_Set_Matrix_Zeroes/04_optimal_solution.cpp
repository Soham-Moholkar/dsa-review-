#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        bool firstRowZero = false;
        bool firstColumnZero = false;
        for(int column = 0; column < columns; column++) if(matrix[0][column] == 0) firstRowZero = true;
        for(int row = 0; row < rows; row++) if(matrix[row][0] == 0) firstColumnZero = true;
        for(int row = 1; row < rows; row++) {
            for(int column = 1; column < columns; column++) {
                if(matrix[row][column] == 0) {
                    matrix[row][0] = 0;
                    matrix[0][column] = 0;
                }
            }
        }
        for(int row = 1; row < rows; row++) {
            for(int column = 1; column < columns; column++) {
                if(matrix[row][0] == 0 || matrix[0][column] == 0) matrix[row][column] = 0;
            }
        }
        if(firstRowZero) for(int column = 0; column < columns; column++) matrix[0][column] = 0;
        if(firstColumnZero) for(int row = 0; row < rows; row++) matrix[row][0] = 0;
    }
};

/*
Time Complexity: O(r × c)
Extra Space: O(1)
Approach: First row and column as markers.
*/
