#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getSecondLargest(vector<int> &arr) {
        long long largestValue = LLONG_MIN;
        for(int i = 0; i < arr.size(); i++) {
            largestValue = max(largestValue, (long long)arr[i]);
        }
        long long secondLargest = LLONG_MIN;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] != largestValue && arr[i] > secondLargest) {
                secondLargest = arr[i];
            }
        }
        if(secondLargest == LLONG_MIN) {
            return -1;
        }
        return secondLargest;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Two complete scans.
*/
