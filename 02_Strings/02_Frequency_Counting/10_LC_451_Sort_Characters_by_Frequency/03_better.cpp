#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;for(char c:s)++freq[c];priority_queue<pair<int,char>> heap;for(auto [c,n]:freq)heap.push({n,c});string out;while(!heap.empty()){auto [n,c]=heap.top();heap.pop();out.append(n,c);}return out;
    }
};
