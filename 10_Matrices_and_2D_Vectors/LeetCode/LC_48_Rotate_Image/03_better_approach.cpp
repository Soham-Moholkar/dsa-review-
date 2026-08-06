#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int row = 0; row < n; row++) {
            for(int column = row + 1; column < n; column++) swap(matrix[row][column], matrix[column][row]);
        }
        for(int row = 0; row < n; row++) reverse(matrix[row].begin(), matrix[row].end());
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Transpose and reverse rows.
*/
