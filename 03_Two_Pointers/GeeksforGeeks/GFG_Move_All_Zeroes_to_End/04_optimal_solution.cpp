#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void pushZerosToEnd(vector<int>& arr) {
        int j = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] != 0) {
                swap(arr[i], arr[j]);
                j++;
            }
        }
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Stable swap.
*/
