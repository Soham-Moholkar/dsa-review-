#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotateby90(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int row = 0; row < n; row++) {
            for(int column = row + 1; column < n; column++) {
                swap(mat[row][column], mat[column][row]);
            }
        }
        reverse(mat.begin(), mat.end());
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Transpose, then reverse the order of rows. After transposition this reverses every column and produces a 90-degree anti-clockwise rotation.
*/
