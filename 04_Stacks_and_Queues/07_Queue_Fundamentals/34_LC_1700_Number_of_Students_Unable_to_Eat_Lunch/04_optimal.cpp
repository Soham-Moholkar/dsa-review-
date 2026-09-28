#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[2]={};for(int x:students)++count[x];for(int x:sandwiches){if(!count[x])break;--count[x];}return count[0]+count[1];
    }
};
