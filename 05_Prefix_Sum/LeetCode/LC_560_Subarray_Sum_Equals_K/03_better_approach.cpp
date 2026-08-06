#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> frequency;
        frequency[0] = 1;
        int prefixSum = 0;
        int answer = 0;
        for(int i = 0; i < nums.size(); i++) {
            prefixSum = prefixSum + nums[i];
            int required = prefixSum - k;
            answer = answer + frequency[required];
            frequency[prefixSum]++;
        }
        return answer;
    }
};

/*
Time Complexity: O(n log n)
Extra Space: O(n)
Approach: Ordered map of prefix frequencies.
*/
