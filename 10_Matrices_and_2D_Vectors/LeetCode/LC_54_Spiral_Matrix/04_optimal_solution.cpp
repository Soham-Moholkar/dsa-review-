#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        while(top <= bottom && left <= right) {
            for(int column = left; column <= right; column++) answer.push_back(matrix[top][column]);
            top++;
            for(int row = top; row <= bottom; row++) answer.push_back(matrix[row][right]);
            right--;
            if(top <= bottom) {
                for(int column = right; column >= left; column--) answer.push_back(matrix[bottom][column]);
                bottom--;
            }
            if(left <= right) {
                for(int row = bottom; row >= top; row--) answer.push_back(matrix[row][left]);
                left++;
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(r × c)
Extra Space: O(1) excluding answer
Approach: Four-boundary spiral.
*/
