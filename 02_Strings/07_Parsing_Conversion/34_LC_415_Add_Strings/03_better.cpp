#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string out;int i=(int)num1.size()-1,j=(int)num2.size()-1,carry=0;while(i>=0||j>=0||carry){int sum=carry+(i>=0?num1[i--]-'0':0)+(j>=0?num2[j--]-'0':0);out+=char('0'+sum%10);carry=sum/10;}reverse(out.begin(),out.end());return out;
    }
};
