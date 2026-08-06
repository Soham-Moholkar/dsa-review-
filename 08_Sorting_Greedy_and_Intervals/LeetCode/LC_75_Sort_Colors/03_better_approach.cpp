#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0,0,0};
        for(int i = 0; i < nums.size(); i++) count[nums[i]]++;
        int index = 0;
        for(int value = 0; value <= 2; value++) {
            while(count[value] > 0) {
                nums[index++] = value;
                count[value]--;
            }
        }
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Counting.
*/
