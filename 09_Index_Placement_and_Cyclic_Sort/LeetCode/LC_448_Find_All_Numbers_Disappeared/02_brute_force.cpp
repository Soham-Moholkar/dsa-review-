#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> answer;
        for(int value = 1; value <= nums.size(); value++) {
            bool found = false;
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] == value) found = true;
            }
            if(!found) answer.push_back(value);
        }
        return answer;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Search for every value.
*/
