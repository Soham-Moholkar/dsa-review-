#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maximumEnding = nums[0];
        int minimumEnding = nums[0];
        int answer = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < 0) {
                swap(maximumEnding, minimumEnding);
            }
            maximumEnding = max(nums[i], maximumEnding * nums[i]);
            minimumEnding = min(nums[i], minimumEnding * nums[i]);
            answer = max(answer, maximumEnding);
        }
        return answer;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Maximum/minimum ending states.
*/
