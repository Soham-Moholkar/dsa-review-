#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> answer;
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0 || nums[i] != nums[i - 1]) {
                answer.push_back(nums[i]);
            }
        }
        for(int i = 0; i < answer.size(); i++) {
            nums[i] = answer[i];
        }
        return answer.size();
    }
};

/*
Time Complexity: O(n)
Extra Space: O(n)
Approach: Use an extra vector.
*/
