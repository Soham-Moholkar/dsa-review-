#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int answer = 0;
        for(int i = 0; i < height.size(); i++) {
            for(int j = i + 1; j < height.size(); j++) {
                int area = min(height[i], height[j]) * (j - i);
                answer = max(answer, area);
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Check every pair.
*/
