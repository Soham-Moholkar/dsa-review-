#include <bits/stdc++.h>
using namespace std;

class ArrayQueue { vector<int> data; size_t head=0; public: void push(int x){data.push_back(x);} void pop(){if(empty())return;++head;if(head==data.size()){data.clear();head=0;}} int front(){return empty()?-1:data[head];} int back(){return empty()?-1:data.back();} bool empty(){return head==data.size();} int size(){return data.size()-head;} };
