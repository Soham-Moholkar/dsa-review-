#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());deque<int> slots;for(int i=0;i<(int)deck.size();++i)slots.push_back(i);vector<int> answer(deck.size());for(int x:deck){answer[slots.front()]=x;slots.pop_front();if(!slots.empty()){slots.push_back(slots.front());slots.pop_front();}}return answer;
    }
};
