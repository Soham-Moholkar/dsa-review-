#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subarrayXor(vector<int>& arr, int k) {
        unordered_map<int, int> frequency;
        frequency[0] = 1;
        int prefixXor = 0;
        long long answer = 0;
        for(int i = 0; i < arr.size(); i++) {
            prefixXor = prefixXor ^ arr[i];
            int required = prefixXor ^ k;
            if(frequency.find(required) != frequency.end()) {
                answer = answer + frequency[required];
            }
            frequency[prefixXor]++;
        }
        return answer;
    }
};

/*
Time Complexity: O(n) average
Extra Space: O(n)
Approach: Hashmap of prefix XOR frequencies.
*/
