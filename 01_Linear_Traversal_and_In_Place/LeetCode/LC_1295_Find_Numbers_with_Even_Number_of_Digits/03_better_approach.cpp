#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int answer = 0;
        for(int i = 0; i < nums.size(); i++) {
            int number = abs(nums[i]);
            int digits = 0;
            if(number == 0) {
                digits = 1;
            }
            while(number > 0) {
                digits++;
                number = number / 10;
            }
            if(digits % 2 == 0) {
                answer++;
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(total digits)
Extra Space: O(1)
Approach: Repeated division by 10.
*/
