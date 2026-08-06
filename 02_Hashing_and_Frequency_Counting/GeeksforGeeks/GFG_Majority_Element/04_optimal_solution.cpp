#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int candidate = 0;
        int count = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(count == 0) {
                candidate = arr[i];
                count = 1;
            }
            else if(arr[i] == candidate) {
                count++;
            }
            else {
                count--;
            }
        }
        count = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == candidate) {
                count++;
            }
        }
        if(count > arr.size() / 2) {
            return candidate;
        }
        return -1;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Boyer-Moore plus verification.
*/
