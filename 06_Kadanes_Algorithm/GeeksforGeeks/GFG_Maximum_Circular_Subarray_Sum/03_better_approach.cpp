#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int circularSubarraySum(vector<int>& arr) {
        int n = arr.size();
        vector<int> doubled = arr;
        for(int i = 0; i < n; i++) {
            doubled.push_back(arr[i]);
        }
        int answer = INT_MIN;
        for(int start = 0; start < n; start++) {
            int sum = 0;
            for(int end = start; end < start + n; end++) {
                sum = sum + doubled[end];
                answer = max(answer, sum);
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(n)
Approach: Duplicate array and bound subarray length.
*/
