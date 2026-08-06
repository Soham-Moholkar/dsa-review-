#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binarysearch(vector<int> &arr, int k) {
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == k) {
                return i;
            }
        }
        return -1;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Linear search.
*/
