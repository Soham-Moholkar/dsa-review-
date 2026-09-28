#include <bits/stdc++.h>
using namespace std;

class MyCircularDeque { vector<int> data;int head=0,count=0;public:explicit MyCircularDeque(int k):data(k){}bool insertFront(int value){if(isFull())return false;head=(head-1+(int)data.size())%data.size();data[head]=value;++count;return true;}bool insertLast(int value){if(isFull())return false;data[(head+count)%data.size()]=value;++count;return true;}bool deleteFront(){if(isEmpty())return false;head=(head+1)%data.size();--count;return true;}bool deleteLast(){if(isEmpty())return false;--count;return true;}int getFront(){return isEmpty()?-1:data[head];}int getRear(){return isEmpty()?-1:data[(head+count-1)%data.size()];}bool isEmpty(){return count==0;}bool isFull(){return count==(int)data.size();} };
