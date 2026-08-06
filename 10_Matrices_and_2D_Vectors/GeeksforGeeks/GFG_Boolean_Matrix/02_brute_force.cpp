#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void booleanMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> original = matrix;
        int rows = matrix.size();
        int columns = matrix[0].size();
        for(int row = 0; row < rows; row++) {
            for(int column = 0; column < columns; column++) {
                if(original[row][column] == 1) {
                    for(int c = 0; c < columns; c++) matrix[row][c] = 1;
                    for(int r = 0; r < rows; r++) matrix[r][column] = 1;
                }
            }
        }
    }
};

/*
Time Complexity: O(r × c × (r+c))
Extra Space: O(r × c)
Approach: Use an unchanged copy for every marker.
*/
