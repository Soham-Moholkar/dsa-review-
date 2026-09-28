#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue { vector<int> data;int head=0,count=0;public: explicit MyCircularQueue(int k):data(k){} bool enQueue(int value){if(isFull())return false;data[(head+count)%data.size()]=value;++count;return true;}bool deQueue(){if(isEmpty())return false;head=(head+1)%data.size();--count;return true;}int Front(){return isEmpty()?-1:data[head];}int Rear(){return isEmpty()?-1:data[(head+count-1)%data.size()];}bool isEmpty(){return count==0;}bool isFull(){return count==(int)data.size();} };
