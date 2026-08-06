#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int answer = 0;
        while(left < right) {
            int smallerHeight = min(height[left], height[right]);
            answer = max(answer, smallerHeight * (right - left));
            while(left < right && height[left] <= smallerHeight) {
                left++;
            }
            while(left < right && height[right] <= smallerHeight) {
                right--;
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Two pointers with equal-height skip.
*/
