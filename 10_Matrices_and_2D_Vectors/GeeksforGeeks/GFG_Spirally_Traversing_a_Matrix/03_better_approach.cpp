#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spirallyTraverse(vector<vector<int>>& mat) {
        vector<int> answer;
        int top = 0, bottom = mat.size() - 1;
        int left = 0, right = mat[0].size() - 1;
        while(top <= bottom && left <= right) {
            for(int c = left; c <= right; c++) answer.push_back(mat[top][c]);
            top++;
            for(int r = top; r <= bottom; r++) answer.push_back(mat[r][right]);
            right--;
            if(top <= bottom) {
                for(int c = right; c >= left; c--) answer.push_back(mat[bottom][c]);
                bottom--;
            }
            if(left <= right) {
                for(int r = bottom; r >= top; r--) answer.push_back(mat[r][left]);
                left++;
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(rows × columns)
Extra Space: O(1) excluding answer
Approach: Boundary traversal.
*/
