#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binarysearch(vector<int> &arr, int k) {
        int left = 0;
        int right = arr.size() - 1;
        int answer = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] == k) {
                answer = mid;
                right = mid - 1; // Keep looking for an earlier occurrence.
            }
            else if(arr[mid] < k) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return answer;
    }
};

/*
Time Complexity: O(log n)
Extra Space: O(1)
Approach: Manual iterative binary search.
*/
