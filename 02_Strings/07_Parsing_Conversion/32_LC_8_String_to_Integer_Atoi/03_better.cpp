#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i=0,n=s.size();while(i<n&&s[i]==' ')++i;int sign=1;if(i<n&&(s[i]=='+'||s[i]=='-'))sign=s[i++]=='-'?-1:1;long long x=0;long long limit=sign==1?INT_MAX:-(long long)INT_MIN;while(i<n&&isdigit((unsigned char)s[i])){int digit=s[i++]-'0';if(x>(limit-digit)/10)return sign==1?INT_MAX:INT_MIN;x=x*10+digit;}return (int)(sign*x);
    }
};
