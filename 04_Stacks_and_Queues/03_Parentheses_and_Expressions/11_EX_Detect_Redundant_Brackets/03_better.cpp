#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasRedundantBrackets(string expression) {
        stack<char> st;for(char c:expression){if(c!=')'){st.push(c);continue;}bool hasOperator=false;while(!st.empty()&&st.top()!='('){char x=st.top();st.pop();hasOperator|=(x=='+'||x=='-'||x=='*'||x=='/');}if(st.empty())return false;st.pop();if(!hasOperator)return true;st.push('a');}return false;
    }
};
