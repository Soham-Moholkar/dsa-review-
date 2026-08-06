#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equilibriumPoint(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++) {
            long long leftSum = 0;
            long long rightSum = 0;
            for(int j = 0; j < i; j++) {
                leftSum = leftSum + arr[j];
            }
            for(int j = i + 1; j < arr.size(); j++) {
                rightSum = rightSum + arr[j];
            }
            if(leftSum == rightSum) {
                return i + 1;
            }
        }
        return -1;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Recalculate both sides.
*/
