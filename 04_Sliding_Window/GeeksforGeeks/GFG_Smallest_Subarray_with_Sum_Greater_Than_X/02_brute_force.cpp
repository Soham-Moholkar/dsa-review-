#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        int answer = INT_MAX;
        for(int start = 0; start < arr.size(); start++) {
            int sum = 0;
            for(int end = start; end < arr.size(); end++) {
                sum = sum + arr[end];
                if(sum > x) {
                    answer = min(answer, end - start + 1);
                    break;
                }
            }
        }
        if(answer == INT_MAX) {
            return 0;
        }
        return answer;
    }
};

/*
Time Complexity: O(n^2)
Extra Space: O(1)
Approach: Try every start and end.
*/
