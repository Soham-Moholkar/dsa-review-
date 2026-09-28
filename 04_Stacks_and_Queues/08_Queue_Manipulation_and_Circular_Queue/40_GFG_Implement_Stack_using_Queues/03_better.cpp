#include <bits/stdc++.h>
using namespace std;

class MyStack { queue<int> q;public:MyStack()=default;void push(int x){q.push(x);for(int i=1,n=q.size();i<n;++i){q.push(q.front());q.pop();}}int pop(){int v=q.front();q.pop();return v;}int top(){return q.front();}bool empty(){return q.empty();} };
