#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double answer = -DBL_MAX;
        for(int start = 0; start + k <= nums.size(); start++) {
            long long sum = 0;
            for(int i = start; i < start + k; i++) {
                sum = sum + nums[i];
            }
            answer = max(answer, (double)sum / k);
        }
        return answer;
    }
};

/*
Time Complexity: O(n × k)
Extra Space: O(1)
Approach: Recalculate every sum.
*/
