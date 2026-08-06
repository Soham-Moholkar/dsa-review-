#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int> original = nums;
        vector<int> current = nums;
        sort(current.begin(), current.end());
        vector<vector<int>> permutations;
        do {
            permutations.push_back(current);
        } while(next_permutation(current.begin(), current.end()));
        for(int i = 0; i < permutations.size(); i++) {
            if(permutations[i] == original) {
                nums = permutations[(i + 1) % permutations.size()];
                return;
            }
        }
    }
};

/*
Time Complexity: O(n! × n)
Extra Space: O(n! × n)
Approach: Generate every unique permutation in lexicographic order, locate the original, and select the next.
*/
