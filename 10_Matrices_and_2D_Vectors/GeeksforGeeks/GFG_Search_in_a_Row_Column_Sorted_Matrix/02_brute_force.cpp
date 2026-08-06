#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        for(int row = 0; row < mat.size(); row++) {
            for(int column = 0; column < mat[0].size(); column++) {
                if(mat[row][column] == x) return true;
            }
        }
        return false;
    }
};

/*
Time Complexity: O(r × c)
Extra Space: O(1)
Approach: Check every cell.
*/
