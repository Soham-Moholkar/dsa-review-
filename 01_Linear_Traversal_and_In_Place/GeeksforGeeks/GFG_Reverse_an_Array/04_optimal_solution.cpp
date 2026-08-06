#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseArray(vector<int> &arr) {
        int left = 0;
        int right = arr.size() - 1;
        while(left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Two-pointer in-place reversal.
*/
