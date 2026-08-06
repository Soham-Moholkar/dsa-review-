#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        vector<int> uniqueValues;
        for(int i = 0; i < arr.size(); i++) {
            if(i == 0 || arr[i] != arr[i - 1]) {
                uniqueValues.push_back(arr[i]);
            }
        }
        for(int i = 0; i < uniqueValues.size(); i++) {
            arr[i] = uniqueValues[i];
        }
        return uniqueValues.size();
    }
};

/*
Time Complexity: O(n)
Extra Space: O(n)
Approach: Use a separate unique vector.
*/
