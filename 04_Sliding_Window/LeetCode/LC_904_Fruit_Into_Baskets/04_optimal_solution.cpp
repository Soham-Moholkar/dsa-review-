#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int answer = 0;
        unordered_map<int, int> frequency;
        for(int right = 0; right < fruits.size(); right++) {
            frequency[fruits[right]]++;
            while(frequency.size() > 2) {
                int outgoing = fruits[left];
                frequency[outgoing]--;
                if(frequency[outgoing] == 0) {
                    frequency.erase(outgoing);
                }
                left++;
            }
            answer = max(answer, right - left + 1);
        }
        return answer;
    }
};

/*
Time Complexity: O(n) average
Extra Space: O(1) distinct keys
Approach: Two-type sliding window.
*/
