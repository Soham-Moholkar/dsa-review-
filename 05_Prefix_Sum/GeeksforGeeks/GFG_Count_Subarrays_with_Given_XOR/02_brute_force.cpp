#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subarrayXor(vector<int>& arr, int k) {
        long long answer = 0;
        for(int start = 0; start < arr.size(); start++) {
            int currentXor = 0;
            for(int end = start; end < arr.size(); end++) {
                currentXor = currentXor ^ arr[end];
                if(currentXor == k) {
                    answer++;
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
