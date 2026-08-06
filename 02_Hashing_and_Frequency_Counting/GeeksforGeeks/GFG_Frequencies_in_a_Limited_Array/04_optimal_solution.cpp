#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void frequencyCount(vector<int>& arr, int N, int P) {
        for(int i = 0; i < N; i++) {
            if(arr[i] > N) {
                arr[i] = 0;
            }
        }
        for(int i = 0; i < N; i++) {
            if(arr[i] > 0) {
                int index = (arr[i] - 1) % N;
                arr[index] = arr[index] + N;
            }
        }
        for(int i = 0; i < N; i++) {
            arr[i] = arr[i] / N;
        }
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Encode counts inside the input array.
*/
