#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        int left = 0;
        long long sum = 0;
        int answer = INT_MAX;
        for(int right = 0; right < arr.size(); right++) {
            sum = sum + arr[right];
            while(sum > x) {
                answer = min(answer, right - left + 1);
                sum = sum - arr[left];
                left++;
            }
        }
        if(answer == INT_MAX) {
            return 0;
        }
        return answer;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Variable sliding window.
*/
