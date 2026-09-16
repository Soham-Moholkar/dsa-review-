#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size(); i++) {
            long long remaining = 1LL * target - numbers[i];
            int left = i + 1;
            int right = numbers.size() - 1;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                if(numbers[mid] == remaining) {
                    return {i + 1, mid + 1};
                }
                else if(numbers[mid] < remaining) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        return {-1, -1};
    }
};

/*
Time Complexity: O(n log n)
Extra Space: O(1)
Approach: Binary search the complement.
*/
