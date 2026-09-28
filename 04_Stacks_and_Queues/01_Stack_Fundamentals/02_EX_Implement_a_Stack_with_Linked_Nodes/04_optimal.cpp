#include <bits/stdc++.h>
using namespace std;

class LinkedStack { struct Node{int value;Node* next;Node(int v,Node* n):value(v),next(n){}}; Node* head=nullptr; int count=0; public: LinkedStack()=default; LinkedStack(const LinkedStack&)=delete; LinkedStack& operator=(const LinkedStack&)=delete; ~LinkedStack(){while(head)pop();} void push(int x){head=new Node(x,head);++count;} void pop(){if(!head)return;Node* old=head;head=head->next;delete old;--count;} int top(){return head?head->value:-1;} bool empty(){return !head;} int size(){return count;} };
