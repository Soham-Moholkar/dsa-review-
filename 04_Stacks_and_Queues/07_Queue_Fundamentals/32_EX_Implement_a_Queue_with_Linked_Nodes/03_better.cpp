#include <bits/stdc++.h>
using namespace std;

class LinkedQueue { struct Node{int value;Node* next;explicit Node(int v):value(v),next(nullptr){}};Node* head=nullptr;Node* tail=nullptr;int count=0; public: LinkedQueue()=default;LinkedQueue(const LinkedQueue&)=delete;LinkedQueue& operator=(const LinkedQueue&)=delete;~LinkedQueue(){while(head)pop();}void push(int x){Node* node=new Node(x);if(tail)tail->next=node;else head=node;tail=node;++count;}void pop(){if(!head)return;Node* old=head;head=head->next;if(!head)tail=nullptr;delete old;--count;}int front(){return head?head->value:-1;}int back(){return tail?tail->value:-1;}bool empty(){return !head;}int size(){return count;} };
