#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());queue<int> positions;for(int i=0;i<(int)deck.size();++i)positions.push(i);vector<int> out(deck.size());for(int value:deck){int pos=positions.front();positions.pop();out[pos]=value;if(!positions.empty()){positions.push(positions.front());positions.pop();}}return out;
    }
};
