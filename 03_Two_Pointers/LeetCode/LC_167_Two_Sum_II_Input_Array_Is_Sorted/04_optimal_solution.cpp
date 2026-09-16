#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while(left < right) {
            long long sum = 1LL * numbers[left] + numbers[right];
            if(sum == target) {
                return {left + 1, right + 1};
            }
            else if(sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
        return {-1, -1};
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Opposite-end two pointers.
*/
