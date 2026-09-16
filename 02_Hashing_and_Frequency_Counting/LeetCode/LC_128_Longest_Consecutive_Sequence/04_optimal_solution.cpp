#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> values(nums.begin(), nums.end());
        int answer = 0;
        for(auto value : values) {
            if(value == INT_MIN || values.find(value - 1) == values.end()) {
                int currentValue = value;
                int length = 1;
                while(currentValue != INT_MAX && values.find(currentValue + 1) != values.end()) {
                    currentValue++;
                    length++;
                }
                answer = max(answer, length);
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(n) average
Extra Space: O(n)
Approach: Hash set sequence starts.
*/
