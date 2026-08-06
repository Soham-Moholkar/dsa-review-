#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool subArrayExists(vector<int>& arr) {
        for(int start = 0; start < arr.size(); start++) {
            long long sum = 0;
            for(int end = start; end < arr.size(); end++) {
                sum = sum + arr[end];
                if(sum == 0) {
                    return true;
                }
            }
        }
        return false;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Enumerate all subarrays.
*/
