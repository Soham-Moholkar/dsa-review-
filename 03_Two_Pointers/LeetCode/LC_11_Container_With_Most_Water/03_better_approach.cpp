#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int answer = 0;
        while(left < right) {
            int area = min(height[left], height[right]) * (right - left);
            answer = max(answer, area);
            if(height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Two pointers.
*/
