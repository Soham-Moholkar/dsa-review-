#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        long long sum=0,last=0,number=0;char op='+';for(int i=0;i<=(int)s.size();++i){char c=i==(int)s.size()?'+':s[i];if(c==' ')continue;if(isdigit((unsigned char)c)){number=number*10+c-'0';continue;}if(op=='+'){sum+=last;last=number;}else if(op=='-'){sum+=last;last=-number;}else if(op=='*')last*=number;else last/=number;op=c;number=0;}return (int)(sum+last);
    }
};
