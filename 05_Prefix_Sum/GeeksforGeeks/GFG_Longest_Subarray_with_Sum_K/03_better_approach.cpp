#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        map<long long, int> firstIndex;
        firstIndex[0] = -1;
        long long prefixSum = 0;
        int answer = 0;
        for(int i = 0; i < arr.size(); i++) {
            prefixSum = prefixSum + arr[i];
            long long required = prefixSum - k;
            if(firstIndex.find(required) != firstIndex.end()) {
                answer = max(answer, i - firstIndex[required]);
            }
            if(firstIndex.find(prefixSum) == firstIndex.end()) {
                firstIndex[prefixSum] = i;
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(n log n)
Extra Space: O(n)
Approach: Prefix sum with earliest-index map.
*/
