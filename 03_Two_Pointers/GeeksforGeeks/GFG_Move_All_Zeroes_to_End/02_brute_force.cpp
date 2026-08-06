#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void pushZerosToEnd(vector<int>& arr) {
        vector<int> answer;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] != 0) {
                answer.push_back(arr[i]);
            }
        }
        while(answer.size() < arr.size()) {
            answer.push_back(0);
        }
        arr = answer;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(n)
Approach: Use a new vector.
*/
