#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        int j = 1;

        for(int i = 0; i < nums.size(); i++) {

            // j is not reset for every i and can become nums.size().
            if(nums[i] == nums[j]) {
                return true;
            }

            // Only one comparison is made for each i.
            j++;
        }

        return false;
    }
};
