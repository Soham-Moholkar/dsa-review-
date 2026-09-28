#include <bits/stdc++.h>
using namespace std;

class MinStack { vector<pair<int,int>> st; public: MinStack()=default; void push(int val){st.push_back({val,st.empty()?val:min(val,st.back().second)});} void pop(){st.pop_back();} int top(){return st.back().first;} int getMin(){return st.back().second;} };
