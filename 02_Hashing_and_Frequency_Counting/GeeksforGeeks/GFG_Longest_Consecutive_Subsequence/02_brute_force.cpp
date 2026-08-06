#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int answer = 0;
        for(int i = 0; i < arr.size(); i++) {
            int currentValue = arr[i];
            int length = 1;
            while(true) {
                bool found = false;
                for(int j = 0; j < arr.size(); j++) {
                    if(arr[j] == currentValue + 1) {
                        found = true;
                        break;
                    }
                }
                if(!found) {
                    break;
                }
                currentValue++;
                length++;
            }
            answer = max(answer, length);
        }
        return answer;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Search for every next value.
*/
