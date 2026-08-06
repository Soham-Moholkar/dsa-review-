#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size() + 1;
        int answer = 0;
        for(int value = 1; value <= n; value++) {
            answer = answer ^ value;
        }
        for(int i = 0; i < arr.size(); i++) {
            answer = answer ^ arr[i];
        }
        return answer;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: XOR full range and values.
*/
