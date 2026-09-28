#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;for(auto& op:operations){if(op=="C")scores.pop_back();else if(op=="D")scores.push_back(2*scores.back());else if(op=="+")scores.push_back(scores.back()+scores[scores.size()-2]);else scores.push_back(stoi(op));}return accumulate(scores.begin(),scores.end(),0);
    }
};
