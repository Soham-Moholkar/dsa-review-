#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int maximumEnding = arr[0];
        int minimumEnding = arr[0];
        int answer = arr[0];
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] < 0) {
                swap(maximumEnding, minimumEnding);
            }
            maximumEnding = max(arr[i], maximumEnding * arr[i]);
            minimumEnding = min(arr[i], minimumEnding * arr[i]);
            answer = max(answer, maximumEnding);
        }
        return answer;
    }
};

/*
Time Complexity: O(n)
Extra Space: O(1)
Approach: Track maximum and minimum ending products.
*/
