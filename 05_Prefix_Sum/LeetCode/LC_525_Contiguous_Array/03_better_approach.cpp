#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> firstIndex;
        firstIndex[0] = -1;
        int prefixSum = 0;
        int answer = 0;
        for(int i = 0; i < nums.size(); i++) {
            prefixSum = prefixSum + (nums[i] == 0 ? -1 : 1);
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
Time Complexity: O(n log n)
Extra Space: O(n)
Approach: Ordered map of transformed prefixes.
*/
