#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        int repeating = -1;
        for(int i = 0; i < n; i++) {
            int value = abs(arr[i]);
            int index = value - 1;
            if(arr[index] < 0) {
                repeating = value;
            }
            else {
                arr[index] = -arr[index];
            }
        }
        int missing = -1;
        for(int i = 0; i < n; i++) {
            if(arr[i] > 0) {
                missing = i + 1;
                break;
            }
        }
        return {repeating, missing};
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Sign marking.
*/
