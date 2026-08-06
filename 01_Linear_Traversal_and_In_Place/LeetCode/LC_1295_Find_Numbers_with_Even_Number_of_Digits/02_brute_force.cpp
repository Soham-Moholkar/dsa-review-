#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int answer = 0;
        for(int i = 0; i < nums.size(); i++) {
            string value = to_string(abs(nums[i]));
            if(value.size() % 2 == 0) {
                answer++;
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(total digits)
Extra Space: O(max digits)
Approach: Convert every number to text.
*/
