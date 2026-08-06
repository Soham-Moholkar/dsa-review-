#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int, int> getMinMax(vector<int> &arr) {
        int minimumValue = arr[0];
        int maximumValue = arr[0];
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] < minimumValue) {
                minimumValue = arr[i];
            }
            if(arr[i] > maximumValue) {
                maximumValue = arr[i];
            }
        }
        return {minimumValue, maximumValue};
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: One combined scan.
*/
