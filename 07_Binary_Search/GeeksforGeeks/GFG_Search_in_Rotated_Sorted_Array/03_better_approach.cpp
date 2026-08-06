#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int key) {
        int n = arr.size();
        int left = 0;
        int right = n - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] > arr[right]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        int pivot = left;
        if(key >= arr[pivot] && key <= arr[n - 1]) {
            left = pivot;
            right = n - 1;
        }
        else {
            left = 0;
            right = pivot - 1;
        }
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] == key) return mid;
            if(arr[mid] < key) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};

/*
Time Complexity: O(log n)
Extra Space: O(1)
Approach: Find pivot, then ordinary binary search.
*/
