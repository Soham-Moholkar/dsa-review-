#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        int n = arr.size();
        vector<int> frequency(n, 0);
        for(int i = 0; i < n; i++) frequency[arr[i]]++;
        vector<int> answer;
        for(int value = 0; value < n; value++) {
            if(frequency[value] > 1) answer.push_back(value);
        }
        if(answer.empty()) answer.push_back(-1);
        return answer;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(n)
Approach: Frequency vector.
*/
