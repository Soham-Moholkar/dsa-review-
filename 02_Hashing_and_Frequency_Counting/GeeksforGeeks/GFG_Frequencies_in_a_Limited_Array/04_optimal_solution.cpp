#include <bits/stdc++.h>
using namespace std;

// Handbook contract: N == arr.size(), values in [1, P].
// Replace arr with frequencies of 1..N; ignore original values above N.
class Solution {
public:
    void frequencyCount(vector<int>& arr, int N, int P) {
        (void)P;
        for (int &value : arr) {
            if (value > N) value = 0;
        }
        int i = 0;
        while (i < N) {
            if (arr[i] <= 0) {
                ++i; // Zero means consumed; negatives store counts.
                continue;
            }
            int index = arr[i] - 1;
            if (arr[index] > 0) {
                // Preserve the unprocessed value before using its cell as a counter.
                arr[i] = arr[index];
                arr[index] = -1;
            } else {
                --arr[index];
                arr[i] = 0;
                ++i;
            }
        }
        for (int &count : arr) count = -count;
    }
};
// O(N) time, O(1) extra space. Counts stay within [-N, 0], avoiding N*N overflow.
