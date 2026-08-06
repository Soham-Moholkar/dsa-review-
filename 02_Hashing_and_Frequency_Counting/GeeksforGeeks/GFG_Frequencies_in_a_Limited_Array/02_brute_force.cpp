#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void frequencyCount(vector<int>& arr, int N, int P) {
        vector<int> frequency(N, 0);
        for(int value = 1; value <= N; value++) {
            for(int i = 0; i < N; i++) {
                if(arr[i] == value) {
                    frequency[value - 1]++;
                }
            }
        }
        arr = frequency;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(n)
Approach: Count every value separately.
*/
