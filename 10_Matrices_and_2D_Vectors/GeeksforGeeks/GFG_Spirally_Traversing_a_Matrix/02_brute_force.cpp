#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spirallyTraverse(vector<vector<int>>& mat) {
        int rows = mat.size();
        int columns = mat[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(columns, false));
        vector<int> answer;
        int directions[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int direction = 0;
        int row = 0;
        int column = 0;
        for(int step = 0; step < rows * columns; step++) {
            answer.push_back(mat[row][column]);
            visited[row][column] = true;
            int nextRow = row + directions[direction][0];
            int nextColumn = column + directions[direction][1];
            if(nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn]) {
                direction = (direction + 1) % 4;
                nextRow = row + directions[direction][0];
                nextColumn = column + directions[direction][1];
            }
            row = nextRow;
            column = nextColumn;
        }
        return answer;
    }
};

/*
Time Complexity: O(rows × columns)
Extra Space: O(rows × columns)
Approach: Simulation with visited cells and directions.
*/
