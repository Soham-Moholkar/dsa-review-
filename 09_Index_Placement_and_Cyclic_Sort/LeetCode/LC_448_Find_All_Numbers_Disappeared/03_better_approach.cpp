#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> frequency(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++) frequency[nums[i]]++;
        vector<int> answer;
        for(int value = 1; value <= nums.size(); value++) {
            if(frequency[value] == 0) answer.push_back(value);
        }
        return answer;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(n)
Approach: Frequency vector.
*/
