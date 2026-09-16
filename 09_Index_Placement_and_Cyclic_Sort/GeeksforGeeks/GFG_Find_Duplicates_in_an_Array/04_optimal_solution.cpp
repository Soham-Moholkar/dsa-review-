#include <bits/stdc++.h>
using namespace std;

// Handbook contract: n values in [0, n-1]; sorted duplicates, or {-1}.
class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        int n = arr.size();
        // Shift original values so zero can mean "consumed".
        for (int &value : arr) ++value;
        int i = 0;
        while (i < n) {
            if (arr[i] <= 0) {
                ++i;
                continue;
            }
            int index = arr[i] - 1;
            if (arr[index] > 0) {
                arr[i] = arr[index];
                arr[index] = -1;
            } else {
                --arr[index];
                arr[i] = 0;
                ++i;
            }
        }
        vector<int> answer;
        for (int value = 0; value < n; ++value) {
            if (arr[value] < -1) answer.push_back(value);
        }
        if (answer.empty()) answer.push_back(-1);
        return answer;
    }
};
// O(n) time, O(1) auxiliary space excluding output. Input becomes negative counts.
