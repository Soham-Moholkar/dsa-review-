#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        auto best=[&](char target){int l=0,changes=0,answer=0;for(int r=0;r<(int)answerKey.size();++r){changes+=answerKey[r]!=target;while(changes>k)changes-=answerKey[l++]!=target;answer=max(answer,r-l+1);}return answer;};return max(best('T'),best('F'));
    }
};
