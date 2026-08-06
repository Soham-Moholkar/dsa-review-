#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int answer = 0;
        for(int i = 0; i < nums.size(); i++) {
            int number = nums[i];
            int digits = 0;
            do {
                digits++;
                number = number / 10;
            } while(number != 0);
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
Approach: Digit count with division and no extra storage.
*/
