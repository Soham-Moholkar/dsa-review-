#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int answer = 0;
        for(int start = 0; start < fruits.size(); start++) {
            unordered_set<int> types;
            for(int end = start; end < fruits.size(); end++) {
                types.insert(fruits[end]);
                if(types.size() > 2) {
                    break;
                }
                answer = max(answer, end - start + 1);
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1) distinct keys
Approach: Check every starting index.
*/
