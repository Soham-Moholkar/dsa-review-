#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largest(vector<int> &arr) {
        int largestValue = arr[0];
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] > largestValue) {
                largestValue = arr[i];
            }
        }
        return largestValue;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Single linear scan.
*/
