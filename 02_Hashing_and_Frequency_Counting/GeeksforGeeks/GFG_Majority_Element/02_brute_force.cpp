#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++) {
            int count = 0;
            for(int j = 0; j < arr.size(); j++) {
                if(arr[j] == arr[i]) {
                    count++;
                }
            }
            if(count > arr.size() / 2) {
                return arr[i];
            }
        }
        return -1;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Count each candidate.
*/
