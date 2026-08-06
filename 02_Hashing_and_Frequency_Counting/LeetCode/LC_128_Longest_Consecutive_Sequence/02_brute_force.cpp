#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int answer = 0;
        for(int i = 0; i < nums.size(); i++) {
            int currentValue = nums[i];
            int length = 1;
            while(find(nums.begin(), nums.end(), currentValue + 1) != nums.end()) {
                currentValue++;
                length++;
            }
            answer = max(answer, length);
        }
        return answer;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Repeated linear existence search.
*/
