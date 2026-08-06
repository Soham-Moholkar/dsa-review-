#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> answer(n, vector<int>(n));
        for(int row = 0; row < n; row++) {
            for(int column = 0; column < n; column++) {
                answer[column][n - row - 1] = matrix[row][column];
            }
        }
        matrix = answer;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(n^2)
Approach: Use an extra matrix.
*/
