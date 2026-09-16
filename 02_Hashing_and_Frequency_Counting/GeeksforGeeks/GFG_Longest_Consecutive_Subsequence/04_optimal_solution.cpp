#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> values;
        for(int i = 0; i < arr.size(); i++) {
            values.insert(arr[i]);
        }
        int maximumLength = 0;
        for(auto value : values) {
            if(value == INT_MIN || values.find(value - 1) == values.end()) {
                int currentValue = value;
                int currentLength = 1;
                while(currentValue != INT_MAX && values.find(currentValue + 1) != values.end()) {
                    currentValue++;
                    currentLength++;
                }
                maximumLength = max(maximumLength, currentLength);
            }
        }
        return maximumLength;
    }
};

/*
Time Complexity: O(n) average
Extra Space: O(n)
Approach: Hash set and sequence starts.
*/
