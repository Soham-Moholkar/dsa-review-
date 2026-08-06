#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countDistinct(vector<int>& arr, int k) {
        vector<int> answer;
        for(int start = 0; start + k <= arr.size(); start++) {
            unordered_set<int> values;
            for(int i = start; i < start + k; i++) {
                values.insert(arr[i]);
            }
            answer.push_back(values.size());
        }
        return answer;
    }
};

/*
Time Complexity: O(n × k)
Extra Space: O(k)
Approach: Build a set for each window.
*/
