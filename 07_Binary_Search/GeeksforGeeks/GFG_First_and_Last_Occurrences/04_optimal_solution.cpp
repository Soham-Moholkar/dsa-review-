#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> find(vector<int>& arr, int x) {
        int first = -1;
        int last = -1;
        int left = 0;
        int right = arr.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] >= x) {
                if(arr[mid] == x) {
                    first = mid;
                }
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        left = 0;
        right = arr.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] <= x) {
                if(arr[mid] == x) {
                    last = mid;
                }
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return {first, last};
    }
};

/*
Time Complexity: O(log n)
Extra Space: O(1)
Approach: Two boundary binary searches.
*/
