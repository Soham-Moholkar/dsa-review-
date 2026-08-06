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
        for(int step = 0; step < k; step++) {
            int lastValue = nums[n - 1];
            for(int i = n - 1; i > 0; i--) {
                nums[i] = nums[i - 1];
            }
            nums[0] = lastValue;
        }
    }
};

/*
Time Complexity: O(n × k)
Extra Space: O(1)
Approach: Rotate one step k times.
*/
