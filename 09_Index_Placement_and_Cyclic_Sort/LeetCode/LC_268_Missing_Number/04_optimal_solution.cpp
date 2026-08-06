#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int answer = nums.size();
        for(int i = 0; i < nums.size(); i++) {
            answer = answer ^ i;
            answer = answer ^ nums[i];
        }
        return answer;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: XOR indexes and values.
*/
