#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int answer = 0;
        for(int start = 0; start < arr.size(); start++) {
            long long sum = 0;
            for(int end = start; end < arr.size(); end++) {
                sum = sum + arr[end];
                if(sum == k) {
                    answer = max(answer, end - start + 1);
                }
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Enumerate all subarrays.
*/
