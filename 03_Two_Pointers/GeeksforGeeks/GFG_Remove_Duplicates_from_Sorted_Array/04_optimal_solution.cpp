#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        if(arr.size() == 0) {
            return 0;
        }
        int j = 0;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] != arr[j]) {
                j++;
                arr[j] = arr[i];
            }
        }
        return j + 1;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Read/write two pointers.
*/
