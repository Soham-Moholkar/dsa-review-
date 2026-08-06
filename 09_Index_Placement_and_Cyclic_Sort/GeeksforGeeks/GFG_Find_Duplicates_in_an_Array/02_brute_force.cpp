#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int> answer;
        int n = arr.size();
        for(int value = 0; value < n; value++) {
            int count = 0;
            for(int i = 0; i < n; i++) {
                if(arr[i] == value) count++;
            }
            if(count > 1) answer.push_back(value);
        }
        if(answer.empty()) answer.push_back(-1);
        return answer;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Count every value separately.
*/
