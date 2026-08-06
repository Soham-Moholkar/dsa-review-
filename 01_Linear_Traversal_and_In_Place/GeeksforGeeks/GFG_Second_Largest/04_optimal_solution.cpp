#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getSecondLargest(vector<int> &arr) {
        int largestValue = INT_MIN;
        int secondLargest = INT_MIN;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] > largestValue) {
                secondLargest = largestValue;
                largestValue = arr[i];
            }
            else if(arr[i] > secondLargest && arr[i] != largestValue) {
                secondLargest = arr[i];
            }
        }
        if(secondLargest == INT_MIN) {
            return -1;
        }
        return secondLargest;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: One scan with two states.
*/
