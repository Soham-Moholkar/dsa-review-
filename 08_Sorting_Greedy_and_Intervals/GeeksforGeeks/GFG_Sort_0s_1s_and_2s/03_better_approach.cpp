#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sort012(vector<int>& arr) {
        int zeroes = 0;
        int ones = 0;
        int twos = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == 0) zeroes++;
            else if(arr[i] == 1) ones++;
            else twos++;
        }
        int index = 0;
        while(zeroes-- > 0) arr[index++] = 0;
        while(ones-- > 0) arr[index++] = 1;
        while(twos-- > 0) arr[index++] = 2;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Count and overwrite.
*/
