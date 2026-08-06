#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) {
            return;
        }
        k = k % n;
        vector<int> answer(n);
        for(int i = 0; i < n; i++) {
            int newIndex = (i + k) % n;
            answer[newIndex] = nums[i];
        }
        nums = answer;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(n)
Approach: Place values in an extra vector.
*/
