#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int row = 0; row < matrix.size(); row++) {
            for(int column = 0; column < matrix[0].size(); column++) {
                if(matrix[row][column] == target) return true;
            }
        }
        return false;
    }
};

/*
Time Complexity: O(r × c)
Extra Space: O(1)
Approach: Scan every cell.
*/
