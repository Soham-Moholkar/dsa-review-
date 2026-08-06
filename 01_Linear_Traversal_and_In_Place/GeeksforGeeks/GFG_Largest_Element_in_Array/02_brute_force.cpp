#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largest(vector<int> &arr) {
        for(int i = 0; i < arr.size(); i++) {
            bool isLargest = true;
            for(int j = 0; j < arr.size(); j++) {
                if(arr[j] > arr[i]) {
                    isLargest = false;
                    break;
                }
            }
            if(isLargest) {
                return arr[i];
            }
        }
        return -1;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Compare every candidate.
*/
