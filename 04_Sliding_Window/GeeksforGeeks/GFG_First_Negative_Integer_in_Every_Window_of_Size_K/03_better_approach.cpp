#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> printFirstNegativeInteger(long long A[], long long N, long long K) {
        vector<int> negativeIndexes;
        for(int i = 0; i < N; i++) {
            if(A[i] < 0) {
                negativeIndexes.push_back(i);
            }
        }
        vector<long long> answer;
        int pointer = 0;
        for(int start = 0; start + K <= N; start++) {
            while(pointer < negativeIndexes.size() && negativeIndexes[pointer] < start) {
                pointer++;
            }
            if(pointer < negativeIndexes.size() && negativeIndexes[pointer] < start + K) {
                answer.push_back(A[negativeIndexes[pointer]]);
            }
            else {
                answer.push_back(0);
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(n)
Approach: Store all negative indexes and advance a pointer.
*/
