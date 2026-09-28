#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string out;for(char c:num){while(k&&!out.empty()&&out.back()>c){out.pop_back();--k;}out+=c;}while(k--&&!out.empty())out.pop_back();int first=out.find_first_not_of('0');return first==string::npos?"0":out.substr(first);
    }
};
