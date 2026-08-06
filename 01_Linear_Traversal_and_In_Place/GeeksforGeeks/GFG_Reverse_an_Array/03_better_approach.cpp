#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseArray(vector<int> &arr) {
        int n = arr.size();
        for(int i = 0; i < n / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[n - i - 1];
            arr[n - i - 1] = temp;
        }
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Swap using indexed half traversal.
*/
