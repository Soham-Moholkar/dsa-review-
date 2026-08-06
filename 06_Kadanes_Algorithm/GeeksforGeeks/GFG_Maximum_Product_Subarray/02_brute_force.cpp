#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int answer = INT_MIN;
        for(int start = 0; start < arr.size(); start++) {
            int product = 1;
            for(int end = start; end < arr.size(); end++) {
                product = product * arr[end];
                answer = max(answer, product);
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Enumerate all products.
*/
