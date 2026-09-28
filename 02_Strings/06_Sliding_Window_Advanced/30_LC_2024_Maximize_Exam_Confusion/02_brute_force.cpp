#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans=0;for(int i=0;i<(int)answerKey.size();++i){int t=0,f=0;for(int j=i;j<(int)answerKey.size();++j){t+=answerKey[j]=='T';f+=answerKey[j]=='F';if(min(t,f)<=k)ans=max(ans,j-i+1);}}return ans;
    }
};
