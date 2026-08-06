#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equilibriumPoint(vector<int>& arr) {
        long long totalSum = 0;
        for(int i = 0; i < arr.size(); i++) {
            totalSum = totalSum + arr[i];
        }
        long long leftSum = 0;
        for(int i = 0; i < arr.size(); i++) {
            totalSum = totalSum - arr[i];
            if(leftSum == totalSum) {
                return i + 1;
            }
            leftSum = leftSum + arr[i];
        }
        return -1;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Total sum and running left sum.
*/
