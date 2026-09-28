#include <bits/stdc++.h>
using namespace std;

class ArrayStack { vector<int> data; public: void push(int x){data.push_back(x);} void pop(){if(!data.empty())data.pop_back();} int top(){return data.empty()?-1:data.back();} bool empty(){return data.empty();} int size(){return data.size();} };
