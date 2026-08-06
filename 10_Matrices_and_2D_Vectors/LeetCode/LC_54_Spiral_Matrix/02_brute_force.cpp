#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(columns, false));
        vector<int> answer;
        int directionRow[4] = {0,1,0,-1};
        int directionColumn[4] = {1,0,-1,0};
        int direction = 0, row = 0, column = 0;
        for(int step = 0; step < rows * columns; step++) {
            answer.push_back(matrix[row][column]);
            visited[row][column] = true;
            int nextRow = row + directionRow[direction];
            int nextColumn = column + directionColumn[direction];
            if(nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn]) {
                direction = (direction + 1) % 4;
                nextRow = row + directionRow[direction];
                nextColumn = column + directionColumn[direction];
            }
            row = nextRow;
            column = nextColumn;
        }
        return answer;
    }
};

/*
Time Complexity: O(r × c)
Extra Space: O(r × c)
Approach: Visited simulation.
*/
