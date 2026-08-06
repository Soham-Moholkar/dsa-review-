#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> original = matrix;
        int rows = matrix.size();
        int columns = matrix[0].size();
        for(int row = 0; row < rows; row++) {
            for(int column = 0; column < columns; column++) {
                if(original[row][column] == 0) {
                    for(int c = 0; c < columns; c++) matrix[row][c] = 0;
                    for(int r = 0; r < rows; r++) matrix[r][column] = 0;
                }
            }
        }
    }
};

/*
Time Complexity: O(r × c × (r+c))
Extra Space: O(r × c)
Approach: Use a copy to preserve original zeroes.
*/
