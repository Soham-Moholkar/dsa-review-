#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            int value = arr[i] % n;
            arr[value] = arr[value] + n;
        }
        vector<int> answer;
        for(int value = 0; value < n; value++) {
            if(arr[value] / n > 1) {
                answer.push_back(value);
            }
        }
        if(answer.empty()) answer.push_back(-1);
        return answer;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: In-place modulo frequency encoding.
*/
