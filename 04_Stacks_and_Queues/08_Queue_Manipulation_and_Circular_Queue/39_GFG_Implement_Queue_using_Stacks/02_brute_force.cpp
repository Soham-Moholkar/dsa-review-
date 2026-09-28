#include <bits/stdc++.h>
using namespace std;

class MyQueue { stack<int> incoming,outgoing;void transfer(){if(!outgoing.empty())return;while(!incoming.empty()){outgoing.push(incoming.top());incoming.pop();}}public:MyQueue()=default;void push(int x){incoming.push(x);}int pop(){transfer();int v=outgoing.top();outgoing.pop();return v;}int peek(){transfer();return outgoing.top();}bool empty(){return incoming.empty()&&outgoing.empty();} };
