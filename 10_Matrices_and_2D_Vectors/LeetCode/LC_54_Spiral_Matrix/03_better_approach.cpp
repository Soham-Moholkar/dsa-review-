#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;
        int top = 0, bottom = matrix.size()-1, left = 0, right = matrix[0].size()-1;
        while(top <= bottom && left <= right) {
            for(int c = left; c <= right; c++) answer.push_back(matrix[top][c]);
            top++;
            for(int r = top; r <= bottom; r++) answer.push_back(matrix[r][right]);
            right--;
            if(top <= bottom) {
                for(int c = right; c >= left; c--) answer.push_back(matrix[bottom][c]);
                bottom--;
            }
            if(left <= right) {
                for(int r = bottom; r >= top; r--) answer.push_back(matrix[r][left]);
                left++;
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(r × c)
Extra Space: O(1) excluding answer
Approach: Boundary traversal.
*/
