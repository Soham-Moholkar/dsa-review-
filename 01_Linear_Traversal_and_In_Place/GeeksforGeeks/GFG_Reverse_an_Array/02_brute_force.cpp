#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseArray(vector<int> &arr) {
        vector<int> answer;
        for(int i = arr.size() - 1; i >= 0; i--) {
            answer.push_back(arr[i]);
        }
        arr = answer;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(n)
Approach: Build a reversed copy.
*/
