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
        for(int column = 0; column < n; column++) {
            int top = 0;
            int bottom = n - 1;
            while(top < bottom) {
                swap(mat[top][column], mat[bottom][column]);
                top++;
                bottom--;
            }
        }
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Transpose then reverse columns.
*/
