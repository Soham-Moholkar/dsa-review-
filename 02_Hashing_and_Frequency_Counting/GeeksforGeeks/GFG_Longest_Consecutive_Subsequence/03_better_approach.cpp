#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        if(arr.size() == 0) {
            return 0;
        }
        sort(arr.begin(), arr.end());
        int currentLength = 1;
        int maximumLength = 1;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] == arr[i - 1]) {
                continue;
            }
            if(arr[i] == arr[i - 1] + 1) {
                currentLength++;
            }
            else {
                currentLength = 1;
            }
            maximumLength = max(maximumLength, currentLength);
        }
        return maximumLength;
    }
};

/*
Time Complexity: O(n log n)
Extra Space: O(1)
Approach: Sort and scan.
*/
