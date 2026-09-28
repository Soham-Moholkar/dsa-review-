#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26]={};for(int i=0;i<(int)s.size();++i)last[s[i]-'a']=i;vector<int> out;int begin=0,end=0;for(int i=0;i<(int)s.size();++i){end=max(end,last[s[i]-'a']);if(i==end){out.push_back(end-begin+1);begin=i+1;}}return out;
    }
};
