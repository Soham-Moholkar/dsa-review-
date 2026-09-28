#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int ans=0;auto vowel=[](char c){return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';}; int count=0;for(int i=0;i<(int)s.size();++i){count+=vowel(s[i]);if(i>=k)count-=vowel(s[i-k]);if(i==k-1||i>=k) ans=max(ans,count);}return ans;
    }
};
