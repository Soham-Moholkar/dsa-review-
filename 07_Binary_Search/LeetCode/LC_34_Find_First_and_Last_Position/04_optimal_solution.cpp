#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int last = -1;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target) {
                if(nums[mid] == target) first = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        left = 0;
        right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] <= target) {
                if(nums[mid] == target) last = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return {first, last};
    }
};

/*
Time Complexity: O(log n)
Extra Space: O(1)
Approach: Two manual binary searches.
*/
