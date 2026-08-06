#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void frequencyCount(vector<int>& arr, int N, int P) {
        vector<int> frequency(N, 0);
        for(int i = 0; i < N; i++) {
            if(arr[i] >= 1 && arr[i] <= N) {
                frequency[arr[i] - 1]++;
            }
        }
        arr = frequency;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(n)
Approach: Use a separate frequency array.
*/
