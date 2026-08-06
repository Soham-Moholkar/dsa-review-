#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spirallyTraverse(vector<vector<int>>& mat) {
        vector<int> answer;
        int top = 0;
        int bottom = mat.size() - 1;
        int left = 0;
        int right = mat[0].size() - 1;
        while(top <= bottom && left <= right) {
            for(int column = left; column <= right; column++) answer.push_back(mat[top][column]);
            top++;
            for(int row = top; row <= bottom; row++) answer.push_back(mat[row][right]);
            right--;
            if(top <= bottom) {
                for(int column = right; column >= left; column--) answer.push_back(mat[bottom][column]);
                bottom--;
            }
            if(left <= right) {
                for(int row = bottom; row >= top; row--) answer.push_back(mat[row][left]);
                left++;
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(rows × columns)
Extra Space: O(1) excluding answer
Approach: Four shrinking boundaries.
*/
