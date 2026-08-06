#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> frequency(n + 1, 0);
        for(int i = 0; i < n; i++) frequency[arr[i]]++;
        int repeating = -1;
        int missing = -1;
        for(int value = 1; value <= n; value++) {
            if(frequency[value] == 0) missing = value;
            if(frequency[value] == 2) repeating = value;
        }
        return {repeating, missing};
    }
};

/*
Time Complexity: O(n)
Extra Space: O(n)
Approach: Frequency array.
*/
