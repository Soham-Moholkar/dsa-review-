#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> printFirstNegativeInteger(long long A[], long long N, long long K) {
        vector<long long> answer;
        for(int start = 0; start + K <= N; start++) {
            long long value = 0;
            for(int i = start; i < start + K; i++) {
                if(A[i] < 0) {
                    value = A[i];
                    break;
                }
            }
            answer.push_back(value);
        }
        return answer;
    }
};

/*
Time Complexity: O(n × k)
Extra Space: O(1)
Approach: Scan each window.
*/
