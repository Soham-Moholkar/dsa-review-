#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")return "0";vector<int> v(num1.size()+num2.size());for(int i=(int)num1.size()-1;i>=0;--i)for(int j=(int)num2.size()-1;j>=0;--j){int k=i+j+1;int sum=(num1[i]-'0')*(num2[j]-'0')+v[k];v[k]=sum%10;v[k-1]+=sum/10;}string out;int i=0;while(i<(int)v.size()&&v[i]==0)++i;for(;i<(int)v.size();++i)out+=char('0'+v[i]);return out.empty()?"0":out;
    }
};
