#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countDistinct(vector<int>& arr, int k) {
        vector<int> answer;
        unordered_map<int, int> frequency;
        for(int i = 0; i < k; i++) {
            frequency[arr[i]]++;
        }
        answer.push_back(frequency.size());
        for(int i = k; i < arr.size(); i++) {
            int outgoing = arr[i - k];
            frequency[outgoing]--;
            if(frequency[outgoing] == 0) {
                frequency.erase(outgoing);
            }
            frequency[arr[i]]++;
            answer.push_back(frequency.size());
        }
        return answer;
    }
};

/*
Time Complexity: O(n) average
Extra Space: O(k)
Approach: Sliding hashmap with zero-count erasure.
*/
