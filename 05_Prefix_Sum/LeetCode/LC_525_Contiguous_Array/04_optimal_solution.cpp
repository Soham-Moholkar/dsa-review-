#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> firstIndex;
        firstIndex[0] = -1;
        int prefixSum = 0;
        int answer = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                prefixSum--;
            }
            else {
                prefixSum++;
            }
            if(firstIndex.find(prefixSum) != firstIndex.end()) {
                answer = max(answer, i - firstIndex[prefixSum]);
            }
            else {
                firstIndex[prefixSum] = i;
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(n) average
Extra Space: O(n)
Approach: Hashmap of earliest transformed prefixes.
*/
