#include <bits/stdc++.h>
using namespace std;

class RecentCounter { deque<int> times;public:RecentCounter()=default;int ping(int t){times.push_back(t);while(!times.empty()&&times.front()<t-3000)times.pop_front();return times.size();} };
