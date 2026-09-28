#!/usr/bin/env python3
"""Build verified study-reference candidates without touching learner attempts."""
import json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
MODULE=ROOT/'04_Stacks_and_Queues'
# Each value is either a method body (normal Solution signature) or a complete
# judge-style class for design exercises, marked by a leading class declaration.
O={
1:r'''class ArrayStack { vector<int> data; public: void push(int x){data.push_back(x);} void pop(){if(!data.empty())data.pop_back();} int top(){return data.empty()?-1:data.back();} bool empty(){return data.empty();} int size(){return data.size();} };''',
2:r'''class LinkedStack { struct Node{int value;Node* next;Node(int v,Node* n):value(v),next(n){}}; Node* head=nullptr; int count=0; public: LinkedStack()=default; LinkedStack(const LinkedStack&)=delete; LinkedStack& operator=(const LinkedStack&)=delete; ~LinkedStack(){while(head)pop();} void push(int x){head=new Node(x,head);++count;} void pop(){if(!head)return;Node* old=head;head=head->next;delete old;--count;} int top(){return head?head->value:-1;} bool empty(){return !head;} int size(){return count;} };''',
3:r'''vector<int> scores;for(auto& op:operations){if(op=="C")scores.pop_back();else if(op=="D")scores.push_back(2*scores.back());else if(op=="+")scores.push_back(scores.back()+scores[scores.size()-2]);else scores.push_back(stoi(op));}return accumulate(scores.begin(),scores.end(),0);''',
4:r'''string out;for(char c:s){if(!out.empty()&&out.back()==c)out.pop_back();else out+=c;}return out;''',
5:r'''stack<int> st;int j=0;for(int value:pushed){st.push(value);while(!st.empty()&&j<(int)popped.size()&&st.top()==popped[j]){st.pop();++j;}}return j==(int)popped.size();''',
6:r'''vector<int> saved;while(!st.empty()){saved.push_back(st.top());st.pop();}st.push(value);for(int i=(int)saved.size()-1;i>=0;--i)st.push(saved[i]);''',
7:r'''function<void(int)> bottom=[&](int x){if(st.empty()){st.push(x);return;}int t=st.top();st.pop();bottom(x);st.push(t);};function<void()> reverse=[&](){if(st.empty())return;int t=st.top();st.pop();reverse();bottom(t);};reverse();''',
8:r'''int depth=(int)st.size()-1-((int)st.size()-1)/2;function<void(int)> remove=[&](int d){if(d==0){st.pop();return;}int x=st.top();st.pop();remove(d-1);st.push(x);};if(!st.empty())remove(depth);''',
9:r'''function<void(int)> insert=[&](int x){if(st.empty()||st.top()<=x){st.push(x);return;}int y=st.top();st.pop();insert(x);st.push(y);};function<void()> sortRec=[&](){if(st.empty())return;int x=st.top();st.pop();sortRec();insert(x);};sortRec();''',
10:r'''stack<char> st;for(char c:s){if(c=='('||c=='['||c=='{')st.push(c);else {if(st.empty())return false;char x=st.top();st.pop();if((c==')'&&x!='(')||(c==']'&&x!='[')||(c=='}'&&x!='{'))return false;}}return st.empty();''',
11:r'''stack<char> st;for(char c:expression){if(c!=')'){st.push(c);continue;}bool hasOperator=false;while(!st.empty()&&st.top()!='('){char x=st.top();st.pop();hasOperator|=(x=='+'||x=='-'||x=='*'||x=='/');}if(st.empty())return false;st.pop();if(!hasOperator)return true;st.push('a');}return false;''',
12:r'''int opens=0,add=0;for(char c:s){if(c=='(')++opens;else if(opens)--opens;else ++add;}return add+opens;''',
13:r'''stack<long long> st;for(auto& s:tokens){if(s=="+"||s=="-"||s=="*"||s=="/"){long long b=st.top();st.pop();long long a=st.top();st.pop();if(s=="+")st.push(a+b);else if(s=="-")st.push(a-b);else if(s=="*")st.push(a*b);else st.push(a/b);}else st.push(stoll(s));}return (int)st.top();''',
14:r'''long long sum=0,last=0,number=0;char op='+';for(int i=0;i<=(int)s.size();++i){char c=i==(int)s.size()?'+':s[i];if(c==' ')continue;if(isdigit((unsigned char)c)){number=number*10+c-'0';continue;}if(op=='+'){sum+=last;last=number;}else if(op=='-'){sum+=last;last=-number;}else if(op=='*')last*=number;else last/=number;op=c;number=0;}return (int)(sum+last);''',
15:r'''vector<int> ans(nums.size(),-1);stack<int> st;for(int i=(int)nums.size()-1;i>=0;--i){while(!st.empty()&&st.top()<=nums[i])st.pop();if(!st.empty())ans[i]=st.top();st.push(nums[i]);}return ans;''',
16:r'''vector<int> ans(nums.size(),-1);stack<int> st;for(int i=(int)nums.size()-1;i>=0;--i){while(!st.empty()&&st.top()>=nums[i])st.pop();if(!st.empty())ans[i]=st.top();st.push(nums[i]);}return ans;''',
17:r'''vector<int> ans(nums.size(),-1);stack<int> st;for(int i=0;i<(int)nums.size();++i){while(!st.empty()&&st.top()<=nums[i])st.pop();if(!st.empty())ans[i]=st.top();st.push(nums[i]);}return ans;''',
18:r'''vector<int> ans(nums.size(),-1);stack<int> st;for(int i=0;i<(int)nums.size();++i){while(!st.empty()&&st.top()>=nums[i])st.pop();if(!st.empty())ans[i]=st.top();st.push(nums[i]);}return ans;''',
19:r'''int n=nums.size();vector<int> ans(n,-1),st;for(int i=2*n-1;i>=0;--i){int x=nums[i%n];while(!st.empty()&&st.back()<=x)st.pop_back();if(i<n&&!st.empty())ans[i]=st.back();st.push_back(x);}return ans;''',
20:r'''class StockSpanner { vector<pair<int,int>> st; public: StockSpanner()=default; int next(int price){int span=1;while(!st.empty()&&st.back().first<=price){span+=st.back().second;st.pop_back();}st.push_back({price,span});return span;} };''',
21:r'''int n=temperatures.size();vector<int> ans(n),st;for(int i=0;i<n;++i){while(!st.empty()&&temperatures[i]>temperatures[st.back()]){int j=st.back();st.pop_back();ans[j]=i-j;}st.push_back(i);}return ans;''',
22:r'''vector<int> st;int best=0,n=heights.size();for(int i=0;i<=n;++i){int h=i==n?0:heights[i];while(!st.empty()&&(i==n||heights[st.back()]>=h)){int height=heights[st.back()];st.pop_back();int left=st.empty()?-1:st.back();best=max(best,height*(i-left-1));}st.push_back(i);}return best;''',
23:r'''if(matrix.empty())return 0;int cols=matrix[0].size(),best=0;vector<int> height(cols);for(auto& row:matrix){for(int j=0;j<cols;++j)height[j]=row[j]=='1'?height[j]+1:0;vector<int> st;for(int j=0;j<=cols;++j){int h=j==cols?0:height[j];while(!st.empty()&&(j==cols||height[st.back()]>=h)){int x=height[st.back()];st.pop_back();best=max(best,x*(j-(st.empty()?-1:st.back())-1));}st.push_back(j);}}return best;''',
24:r'''const long long MOD=1000000007;int n=arr.size();vector<int> left(n),right(n),st;for(int i=0;i<n;++i){while(!st.empty()&&arr[st.back()]>=arr[i])st.pop_back();left[i]=st.empty()?-1:st.back();st.push_back(i);}st.clear();for(int i=n-1;i>=0;--i){while(!st.empty()&&arr[st.back()]>arr[i])st.pop_back();right[i]=st.empty()?n:st.back();st.push_back(i);}long long total=0;for(int i=0;i<n;++i)total=(total+(long long)arr[i]*(i-left[i])*(right[i]-i))%MOD;return (int)total;''',
25:r'''auto contribution=[&](bool maximum){int n=nums.size();vector<int> left(n),right(n),st;for(int i=0;i<n;++i){while(!st.empty()&&(maximum?nums[st.back()]<=nums[i]:nums[st.back()]>=nums[i]))st.pop_back();left[i]=st.empty()?-1:st.back();st.push_back(i);}st.clear();for(int i=n-1;i>=0;--i){while(!st.empty()&&(maximum?nums[st.back()]<nums[i]:nums[st.back()]>nums[i]))st.pop_back();right[i]=st.empty()?n:st.back();st.push_back(i);}long long ans=0;for(int i=0;i<n;++i)ans+=(long long)nums[i]*(i-left[i])*(right[i]-i);return ans;};return contribution(true)-contribution(false);''',
26:r'''vector<int> st;int water=0;for(int i=0;i<(int)height.size();++i){while(!st.empty()&&height[i]>height[st.back()]){int bottom=st.back();st.pop_back();if(st.empty())break;int width=i-st.back()-1;int depth=min(height[i],height[st.back()])-height[bottom];water+=width*depth;}st.push_back(i);}return water;''',
27:r'''class MinStack { vector<pair<int,int>> st; public: MinStack()=default; void push(int val){st.push_back({val,st.empty()?val:min(val,st.back().second)});} void pop(){st.pop_back();} int top(){return st.back().first;} int getMin(){return st.back().second;} };''',
28:r'''vector<int> st;for(int x:asteroids){bool alive=true;while(alive&&x<0&&!st.empty()&&st.back()>0){if(st.back()<-x)st.pop_back();else if(st.back()==-x){st.pop_back();alive=false;}else alive=false;}if(alive)st.push_back(x);}return st;''',
29:r'''string out;for(char c:num){while(k&&!out.empty()&&out.back()>c){out.pop_back();--k;}out+=c;}while(k--&&!out.empty())out.pop_back();int first=out.find_first_not_of('0');return first==string::npos?"0":out.substr(first);''',
30:r'''vector<int> count;vector<string> previous;string part;int value=0;for(char c:s){if(isdigit((unsigned char)c))value=value*10+c-'0';else if(c=='['){count.push_back(value);previous.push_back(part);value=0;part.clear();}else if(c==']'){string block=part;part=previous.back();previous.pop_back();int n=count.back();count.pop_back();while(n--)part+=block;}else part+=c;}return part;''',
31:r'''class ArrayQueue { vector<int> data; size_t head=0; public: void push(int x){data.push_back(x);} void pop(){if(empty())return;++head;if(head==data.size()){data.clear();head=0;}} int front(){return empty()?-1:data[head];} int back(){return empty()?-1:data.back();} bool empty(){return head==data.size();} int size(){return data.size()-head;} };''',
32:r'''class LinkedQueue { struct Node{int value;Node* next;explicit Node(int v):value(v),next(nullptr){}};Node* head=nullptr;Node* tail=nullptr;int count=0; public: LinkedQueue()=default;LinkedQueue(const LinkedQueue&)=delete;LinkedQueue& operator=(const LinkedQueue&)=delete;~LinkedQueue(){while(head)pop();}void push(int x){Node* node=new Node(x);if(tail)tail->next=node;else head=node;tail=node;++count;}void pop(){if(!head)return;Node* old=head;head=head->next;if(!head)tail=nullptr;delete old;--count;}int front(){return head?head->value:-1;}int back(){return tail?tail->value:-1;}bool empty(){return !head;}int size(){return count;} };''',
33:r'''int ans=0;for(int i=0;i<(int)tickets.size();++i)ans+=min(tickets[i],tickets[k]-(i>k));return ans;''',
34:r'''int count[2]={};for(int x:students)++count[x];for(int x:sandwiches){if(!count[x])break;--count[x];}return count[0]+count[1];''',
35:r'''stack<int> st;while(!q.empty()){st.push(q.front());q.pop();}while(!st.empty()){q.push(st.top());st.pop();}''',
36:r'''stack<int> st;int n=q.size();for(int i=0;i<k;++i){st.push(q.front());q.pop();}while(!st.empty()){q.push(st.top());st.pop();}for(int i=0;i<n-k;++i){q.push(q.front());q.pop();}''',
37:r'''int n=q.size();queue<int> first;for(int i=0;i<n/2;++i){first.push(q.front());q.pop();}queue<int> out;while(!first.empty()){out.push(first.front());first.pop();out.push(q.front());q.pop();}q=move(out);''',
38:r'''class MyCircularQueue { vector<int> data;int head=0,count=0;public: explicit MyCircularQueue(int k):data(k){} bool enQueue(int value){if(isFull())return false;data[(head+count)%data.size()]=value;++count;return true;}bool deQueue(){if(isEmpty())return false;head=(head+1)%data.size();--count;return true;}int Front(){return isEmpty()?-1:data[head];}int Rear(){return isEmpty()?-1:data[(head+count-1)%data.size()];}bool isEmpty(){return count==0;}bool isFull(){return count==(int)data.size();} };''',
39:r'''class MyQueue { stack<int> incoming,outgoing;void transfer(){if(!outgoing.empty())return;while(!incoming.empty()){outgoing.push(incoming.top());incoming.pop();}}public:MyQueue()=default;void push(int x){incoming.push(x);}int pop(){transfer();int v=outgoing.top();outgoing.pop();return v;}int peek(){transfer();return outgoing.top();}bool empty(){return incoming.empty()&&outgoing.empty();} };''',
40:r'''class MyStack { queue<int> q;public:MyStack()=default;void push(int x){q.push(x);for(int i=1,n=q.size();i<n;++i){q.push(q.front());q.pop();}}int pop(){int v=q.front();q.pop();return v;}int top(){return q.front();}bool empty(){return q.empty();} };''',
41:r'''deque<int> dq;for(auto& command:commands){istringstream in(command);string op;int x;in>>op;if(op=="push_front"){in>>x;dq.push_front(x);}else if(op=="push_back"){in>>x;dq.push_back(x);}else if(op=="pop_front"&&!dq.empty())dq.pop_front();else if(op=="pop_back"&&!dq.empty())dq.pop_back();}return vector<int>(dq.begin(),dq.end());''',
42:r'''deque<int> dq;vector<int> out;for(int i=0;i<(int)arr.size();++i){if(arr[i]<0)dq.push_back(i);while(!dq.empty()&&dq.front()<=i-k)dq.pop_front();if(i>=k-1)out.push_back(dq.empty()?0:arr[dq.front()]);}return out;''',
43:r'''deque<int> dq;vector<int> out;for(int i=0;i<(int)nums.size();++i){while(!dq.empty()&&dq.front()<=i-k)dq.pop_front();while(!dq.empty()&&nums[dq.back()]<=nums[i])dq.pop_back();dq.push_back(i);if(i>=k-1)out.push_back(nums[dq.front()]);}return out;''',
44:r'''deque<int> lo,hi;int left=0,best=0;for(int right=0;right<(int)nums.size();++right){while(!lo.empty()&&nums[lo.back()]>=nums[right])lo.pop_back();while(!hi.empty()&&nums[hi.back()]<=nums[right])hi.pop_back();lo.push_back(right);hi.push_back(right);while((long long)nums[hi.front()]-nums[lo.front()]>limit){if(lo.front()==left)lo.pop_front();if(hi.front()==left)hi.pop_front();++left;}best=max(best,right-left+1);}return best;''',
45:r'''int n=nums.size(),answer=n+1;vector<long long> sum(n+1);for(int i=0;i<n;++i)sum[i+1]=sum[i]+nums[i];deque<int> dq;for(int i=0;i<=n;++i){while(!dq.empty()&&sum[i]-sum[dq.front()]>=k){answer=min(answer,i-dq.front());dq.pop_front();}while(!dq.empty()&&sum[i]<=sum[dq.back()])dq.pop_back();dq.push_back(i);}return answer==n+1?-1:answer;''',
46:r'''int freq[256]={};queue<char> q;string out;for(char c:s){++freq[(unsigned char)c];q.push(c);while(!q.empty()&&freq[(unsigned char)q.front()]>1)q.pop();out+=q.empty()?'#':q.front();}return out;''',
47:r'''class RecentCounter { queue<int> q;public:RecentCounter()=default;int ping(int t){q.push(t);while(q.front()<t-3000)q.pop();return q.size();} };''',
48:r'''sort(deck.begin(),deck.end());queue<int> positions;for(int i=0;i<(int)deck.size();++i)positions.push(i);vector<int> out(deck.size());for(int value:deck){int pos=positions.front();positions.pop();out[pos]=value;if(!positions.empty()){positions.push(positions.front());positions.pop();}}return out;''',
49:r'''int n=senate.size();queue<int> r,d;for(int i=0;i<n;++i)(senate[i]=='R'?r:d).push(i);while(!r.empty()&&!d.empty()){int a=r.front(),b=d.front();r.pop();d.pop();if(a<b)r.push(a+n);else d.push(b+n);}return r.empty()?"Dire":"Radiant";''',
50:r'''deque<int> q;for(int x:events){if(capacity==0)continue;if((int)q.size()==capacity)q.pop_front();q.push_back(x);}return vector<int>(q.begin(),q.end());''',
51:r'''class MyCircularDeque { vector<int> data;int head=0,count=0;public:explicit MyCircularDeque(int k):data(k){}bool insertFront(int value){if(isFull())return false;head=(head-1+(int)data.size())%data.size();data[head]=value;++count;return true;}bool insertLast(int value){if(isFull())return false;data[(head+count)%data.size()]=value;++count;return true;}bool deleteFront(){if(isEmpty())return false;head=(head+1)%data.size();--count;return true;}bool deleteLast(){if(isEmpty())return false;--count;return true;}int getFront(){return isEmpty()?-1:data[head];}int getRear(){return isEmpty()?-1:data[(head+count-1)%data.size()];}bool isEmpty(){return count==0;}bool isFull(){return count==(int)data.size();} };''',
52:r'''class FrontMiddleBackQueue { deque<int> left,right;void balance(){while(left.size()<right.size()){left.push_back(right.front());right.pop_front();}while(left.size()>right.size()+1){right.push_front(left.back());left.pop_back();}}public:FrontMiddleBackQueue()=default;void pushFront(int val){left.push_front(val);balance();}void pushMiddle(int val){if(left.size()>right.size()){right.push_front(left.back());left.pop_back();}left.push_back(val);}void pushBack(int val){right.push_back(val);balance();}int popFront(){if(left.empty())return -1;int v=left.front();left.pop_front();balance();return v;}int popMiddle(){if(left.empty())return -1;int v=left.back();left.pop_back();balance();return v;}int popBack(){if(left.empty())return -1;int v;if(!right.empty()){v=right.back();right.pop_back();}else{v=left.back();left.pop_back();}balance();return v;} };''',
53:r'''int rows=grid.size(),cols=grid[0].size(),fresh=0;queue<pair<int,int>> q;for(int i=0;i<rows;++i)for(int j=0;j<cols;++j){if(grid[i][j]==2)q.push({i,j});else if(grid[i][j]==1)++fresh;}int time=0,dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};while(!q.empty()&&fresh){int batch=q.size();while(batch--){auto [x,y]=q.front();q.pop();for(int z=0;z<4;++z){int nx=x+dx[z],ny=y+dy[z];if(nx>=0&&nx<rows&&ny>=0&&ny<cols&&grid[nx][ny]==1){grid[nx][ny]=2;--fresh;q.push({nx,ny});}}}++time;}return fresh?-1:time;''',
54:r'''int rows=maze.size(),cols=maze[0].size(),dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};queue<pair<int,int>> q;q.push({entrance[0],entrance[1]});maze[entrance[0]][entrance[1]]='+';int steps=0;while(!q.empty()){int batch=q.size();while(batch--){auto [x,y]=q.front();q.pop();if(steps&&(x==0||x==rows-1||y==0||y==cols-1))return steps;for(int z=0;z<4;++z){int nx=x+dx[z],ny=y+dy[z];if(nx>=0&&nx<rows&&ny>=0&&ny<cols&&maze[nx][ny]=='.'){maze[nx][ny]='+';q.push({nx,ny});}}}++steps;}return -1;''',
55:r'''int n=grid.size(),dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};queue<pair<int,int>> q;for(int i=0;i<n;++i)for(int j=0;j<n;++j)if(grid[i][j]==1)q.push({i,j});if(q.empty()||(int)q.size()==n*n)return -1;int distance=-1;while(!q.empty()){int batch=q.size();++distance;while(batch--){auto [x,y]=q.front();q.pop();for(int z=0;z<4;++z){int nx=x+dx[z],ny=y+dy[z];if(nx>=0&&nx<n&&ny>=0&&ny<n&&grid[nx][ny]==0){grid[nx][ny]=1;q.push({nx,ny});}}}}return distance;''',
}
B={
15:r'''vector<int> out(nums.size(),-1);for(int i=0;i<nums.size();++i)for(int j=i+1;j<nums.size();++j)if(nums[j]>nums[i]){out[i]=nums[j];break;}return out;''',
16:r'''vector<int> out(nums.size(),-1);for(int i=0;i<nums.size();++i)for(int j=i+1;j<nums.size();++j)if(nums[j]<nums[i]){out[i]=nums[j];break;}return out;''',
17:r'''vector<int> out(nums.size(),-1);for(int i=0;i<nums.size();++i)for(int j=i-1;j>=0;--j)if(nums[j]>nums[i]){out[i]=nums[j];break;}return out;''',
18:r'''vector<int> out(nums.size(),-1);for(int i=0;i<nums.size();++i)for(int j=i-1;j>=0;--j)if(nums[j]<nums[i]){out[i]=nums[j];break;}return out;''',
19:r'''int n=nums.size();vector<int> ans(n,-1);for(int i=0;i<n;++i)for(int k=1;k<n;++k)if(nums[(i+k)%n]>nums[i]){ans[i]=nums[(i+k)%n];break;}return ans;''',
21:r'''int n=temperatures.size();vector<int> ans(n);for(int i=0;i<n;++i)for(int j=i+1;j<n;++j)if(temperatures[j]>temperatures[i]){ans[i]=j-i;break;}return ans;''',
22:r'''int best=0;for(int i=0;i<(int)heights.size();++i){int lowest=INT_MAX;for(int j=i;j<(int)heights.size();++j){lowest=min(lowest,heights[j]);best=max(best,lowest*(j-i+1));}}return best;''',
24:r'''const int mod=1000000007;long long sum=0;for(int i=0;i<(int)arr.size();++i){int low=INT_MAX;for(int j=i;j<(int)arr.size();++j){low=min(low,arr[j]);sum=(sum+low)%mod;}}return (int)sum;''',
25:r'''long long sum=0;for(int i=0;i<(int)nums.size();++i){int lo=INT_MAX,hi=INT_MIN;for(int j=i;j<(int)nums.size();++j){lo=min(lo,nums[j]);hi=max(hi,nums[j]);sum+=(long long)hi-lo;}}return sum;''',
26:r'''int total=0;for(int i=0;i<(int)height.size();++i){int left=0,right=0;for(int j=0;j<=i;++j)left=max(left,height[j]);for(int j=i;j<(int)height.size();++j)right=max(right,height[j]);total+=min(left,right)-height[i];}return total;''',
33:r'''queue<pair<int,int>> q;for(int i=0;i<(int)tickets.size();++i)q.push({i,tickets[i]});int time=0;while(!q.empty()){auto [index,count]=q.front();q.pop();++time;if(--count==0){if(index==k)return time;}else q.push({index,count});}return time;''',
34:r'''queue<int> q;for(int x:students)q.push(x);int i=0,rotations=0;while(!q.empty()&&rotations<(int)q.size()){int x=q.front();q.pop();if(x==sandwiches[i]){++i;rotations=0;}else{q.push(x);++rotations;}}return q.size();''',
42:r'''vector<int> out;for(int i=0;i+k<=(int)arr.size();++i){int value=0;for(int j=i;j<i+k;++j)if(arr[j]<0){value=arr[j];break;}out.push_back(value);}return out;''',
43:r'''vector<int> out;for(int i=0;i+k<=(int)nums.size();++i)out.push_back(*max_element(nums.begin()+i,nums.begin()+i+k));return out;''',
44:r'''int best=0;for(int i=0;i<(int)nums.size();++i){int lo=INT_MAX,hi=INT_MIN;for(int j=i;j<(int)nums.size();++j){lo=min(lo,nums[j]);hi=max(hi,nums[j]);if((long long)hi-lo<=limit)best=max(best,j-i+1);}}return best;''',
45:r'''int best=INT_MAX;for(int i=0;i<(int)nums.size();++i){long long sum=0;for(int j=i;j<(int)nums.size();++j){sum+=nums[j];if(sum>=k)best=min(best,j-i+1);}}return best==INT_MAX?-1:best;''',
50:r'''if(capacity==0)return {};int begin=max(0,(int)events.size()-capacity);return vector<int>(events.begin()+begin,events.end());''',
55:r'''int n=grid.size(),best=-1;for(int i=0;i<n;++i)for(int j=0;j<n;++j)if(grid[i][j]==0){int distance=INT_MAX;for(int x=0;x<n;++x)for(int y=0;y<n;++y)if(grid[x][y]==1)distance=min(distance,abs(i-x)+abs(j-y));if(distance!=INT_MAX)best=max(best,distance);}return best;''',
}
BETTER={
22:r'''int n=heights.size(),best=0;vector<int> left(n),right(n),st;for(int i=0;i<n;++i){while(!st.empty()&&heights[st.back()]>=heights[i])st.pop_back();left[i]=st.empty()?-1:st.back();st.push_back(i);}st.clear();for(int i=n-1;i>=0;--i){while(!st.empty()&&heights[st.back()]>=heights[i])st.pop_back();right[i]=st.empty()?n:st.back();st.push_back(i);}for(int i=0;i<n;++i)best=max(best,heights[i]*(right[i]-left[i]-1));return best;''',
26:r'''int n=height.size();if(n==0)return 0;vector<int> left(n),right(n);left[0]=height[0];right[n-1]=height[n-1];for(int i=1;i<n;++i)left[i]=max(left[i-1],height[i]);for(int i=n-2;i>=0;--i)right[i]=max(right[i+1],height[i]);int total=0;for(int i=0;i<n;++i)total+=min(left[i],right[i])-height[i];return total;''',
35:r'''function<void()> reverse=[&](){if(q.empty())return;int x=q.front();q.pop();reverse();q.push(x);};reverse();''',
36:r'''deque<int> d;while(!q.empty()){d.push_back(q.front());q.pop();}for(int i=k-1;i>=0;--i)q.push(d[i]);for(int i=k;i<(int)d.size();++i)q.push(d[i]);''',
37:r'''vector<int> v;while(!q.empty()){v.push_back(q.front());q.pop();}int middle=v.size()/2;for(int i=0;i<middle;++i){q.push(v[i]);q.push(v[i+middle]);}''',
43:r'''vector<int> out;multiset<int> window;for(int i=0;i<(int)nums.size();++i){window.insert(nums[i]);if(i>=k)window.erase(window.find(nums[i-k]));if(i>=k-1)out.push_back(*window.rbegin());}return out;''',
44:r'''multiset<int> window;int left=0,best=0;for(int right=0;right<(int)nums.size();++right){window.insert(nums[right]);while((long long)*window.rbegin()-*window.begin()>limit){window.erase(window.find(nums[left++]));}best=max(best,right-left+1);}return best;''',
46:r'''int count[256]={};string out;for(int i=0;i<(int)s.size();++i){++count[(unsigned char)s[i]];char first='#';for(int j=0;j<=i;++j)if(count[(unsigned char)s[j]]==1){first=s[j];break;}out+=first;}return out;''',
47:r'''class RecentCounter { deque<int> times;public:RecentCounter()=default;int ping(int t){times.push_back(t);while(!times.empty()&&times.front()<t-3000)times.pop_front();return times.size();} };''',
48:r'''sort(deck.begin(),deck.end());deque<int> slots;for(int i=0;i<(int)deck.size();++i)slots.push_back(i);vector<int> answer(deck.size());for(int x:deck){answer[slots.front()]=x;slots.pop_front();if(!slots.empty()){slots.push_back(slots.front());slots.pop_front();}}return answer;''',
50:r'''vector<int> out;for(int x:events){if(capacity<=0)continue;if((int)out.size()==capacity)out.erase(out.begin());out.push_back(x);}return out;''',
53:r'''int rows=grid.size(),cols=grid[0].size(),fresh=0;queue<tuple<int,int,int>> q;for(int i=0;i<rows;++i)for(int j=0;j<cols;++j){if(grid[i][j]==2)q.push({i,j,0});else if(grid[i][j]==1)++fresh;}int time=0,dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};while(!q.empty()){auto [x,y,t]=q.front();q.pop();for(int z=0;z<4;++z){int a=x+dx[z],b=y+dy[z];if(a>=0&&a<rows&&b>=0&&b<cols&&grid[a][b]==1){grid[a][b]=2;--fresh;time=t+1;q.push({a,b,t+1});}}}return fresh?-1:time;''',
}

def write_reference(path,content,previous_generated=None):
    if path.exists():
        old=path.read_text()
        if old==content:return
        if 'DETAILED BEGINNER EXPLANATION' in old:return  # Protect formatted/user-edited work.
        if 'REFERENCE SLOT INTENTIONALLY EMPTY' not in old and old != previous_generated:
            raise RuntimeError(f'Refusing to overwrite authored reference: {path}')
    path.write_text(content)

def build():
    manifest=json.loads((MODULE/'problem_manifest.json').read_text())
    assert len(manifest)==55 and set(O)==set(range(1,56))
    for item in manifest:
        n=item['index'];folder=ROOT/item['folder']
        for file,body in [('02_brute_force.cpp',B.get(n,O[n])),('03_better_approach.cpp',BETTER.get(n,O[n])),('04_optimal_solution.cpp',O[n])]:
            code='#include <bits/stdc++.h>\nusing namespace std;\n\n'
            if item['signature'].startswith('class '):code+=body+'\n'
            else:code+=f'class Solution {{\npublic:\n    {item["signature"]} {{\n        {body}\n    }}\n}};\n'
            fallback='#include <bits/stdc++.h>\nusing namespace std;\n\n'
            if item['signature'].startswith('class '):fallback+=O[n]+'\n'
            else:fallback+=f'class Solution {{\npublic:\n    {item["signature"]} {{\n        {O[n]}\n    }}\n}};\n'
            write_reference(folder/file,code,fallback if file=='03_better_approach.cpp' else None)
        if not (folder/'solution.md').exists():
            (folder/'solution.md').write_text(f'''# {item['title']} — reference discussion

## Contract

`{item['signature']}` — [{item['platform']} problem]({item['url']}). The live judge may use a different C++ method name or parameters; adapt a copy of your code, not the first attempt.

## Recognition cue

{item['goal']}

## Approach progression

| File | Role |
|---|---|
| [Brute force](02_brute_force.cpp) | {'Direct baseline for comparison' if n in B else 'Same efficient method; no distinct baseline recorded'} |
| [Better](03_better_approach.cpp) | {'Intermediate alternative' if n in BETTER else 'Same efficient method; no distinct intermediate recorded'} |
| [Optimal](04_optimal_solution.cpp) | Efficient reference |

For a concrete dry run, trace the first case in `testcases.md` and identify what state each container stores. Approach labels are not a promise that all three slots have different complexity; avoid inventing an algorithm to fill a slot.

Reference availability never represents personal completion or mastery.
''')
    print('Prepared 55 Stack/Queue problems with three compilable reference files each.')

if __name__=='__main__':build()
