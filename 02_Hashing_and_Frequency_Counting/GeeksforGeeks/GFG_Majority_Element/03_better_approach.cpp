#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& arr) {
        unordered_map<int, int> frequency;
        for(int i = 0; i < arr.size(); i++) {
            frequency[arr[i]]++;
            if(frequency[arr[i]] > arr.size() / 2) {
                return arr[i];
            }
        }
        return -1;
    }
};

/*
Time Complexity: O(n) average
Extra Space: O(n)
Approach: Frequency hashmap.
*/
