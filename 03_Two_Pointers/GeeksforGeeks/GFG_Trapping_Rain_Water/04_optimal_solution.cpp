#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxWater(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        int leftMaximum = 0;
        int rightMaximum = 0;
        long long water = 0;
        while(left <= right) {
            if(arr[left] <= arr[right]) {
                if(arr[left] >= leftMaximum) {
                    leftMaximum = arr[left];
                }
                else {
                    water = water + leftMaximum - arr[left];
                }
                left++;
            }
            else {
                if(arr[right] >= rightMaximum) {
                    rightMaximum = arr[right];
                }
                else {
                    water = water + rightMaximum - arr[right];
                }
                right--;
            }
        }
        return water;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Two pointers with running boundaries.
*/
