#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotateby90(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> answer(n, vector<int>(n));
        for(int row = 0; row < n; row++) {
            for(int column = 0; column < n; column++) {
                answer[n - column - 1][row] = mat[row][column];
            }
        }
        mat = answer;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(n^2)
Approach: Use an extra matrix.
*/
