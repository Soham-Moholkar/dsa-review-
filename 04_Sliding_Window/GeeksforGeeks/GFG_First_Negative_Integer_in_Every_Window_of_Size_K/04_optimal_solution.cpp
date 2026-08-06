#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> printFirstNegativeInteger(long long A[], long long N, long long K) {
        deque<int> negativeIndexes;
        vector<long long> answer;
        for(int i = 0; i < N; i++) {
            if(A[i] < 0) {
                negativeIndexes.push_back(i);
            }
            if(i >= K - 1) {
                int windowStart = i - K + 1;
                while(!negativeIndexes.empty() && negativeIndexes.front() < windowStart) {
                    negativeIndexes.pop_front();
                }
                if(negativeIndexes.empty()) {
                    answer.push_back(0);
                }
                else {
                    answer.push_back(A[negativeIndexes.front()]);
                }
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(k)
Approach: Deque of negative indexes.
*/
