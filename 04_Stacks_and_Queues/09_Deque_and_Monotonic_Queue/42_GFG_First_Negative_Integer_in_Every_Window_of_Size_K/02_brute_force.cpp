#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        vector<int> out;for(int i=0;i+k<=(int)arr.size();++i){int value=0;for(int j=i;j<i+k;++j)if(arr[j]<0){value=arr[j];break;}out.push_back(value);}return out;
    }
};
