#!/usr/bin/env python3
"""Build reviewed C++ study references for the numbered Strings curriculum.

Never reads or writes 01_original_attempt.cpp. Re-run only after reviewing
changes in reference slots; populated slots are not silently overwritten.
"""
import json
import pathlib
ROOT=pathlib.Path(__file__).resolve().parents[1]
MODULE=ROOT/'02_Strings'
# Method bodies use the signatures already recorded in the module manifest.
O={
1:r'''int l=0,r=(int)s.size()-1; while(l<r) swap(s[l++],s[r--]);''',
2:r'''for(char &c:s) if(c>='A'&&c<='Z') c=char(c-'A'+'a'); return s;''',
3:r'''int i=(int)s.size()-1; while(i>=0&&s[i]==' ') --i; int end=i; while(i>=0&&s[i]!=' ') --i; return end-i;''',
4:r'''string out; int i=0; while(i<(int)word1.size()||i<(int)word2.size()){if(i<(int)word1.size()) out+=word1[i]; if(i<(int)word2.size()) out+=word2[i]; ++i;} return out;''',
5:r'''string out; int i=(int)s.size()-1; while(i>=0){while(i>=0&&s[i]==' ') --i; if(i<0) break; int end=i; while(i>=0&&s[i]!=' ') --i; if(!out.empty()) out+=' '; out+=s.substr(i+1,end-i);} return out;''',
6:r'''int cnt[256]={}; for(unsigned char c:s) ++cnt[c]; for(int i=0;i<(int)s.size();++i) if(cnt[(unsigned char)s[i]]==1) return i; return -1;''',
7:r'''int cnt[256]={}; for(unsigned char c:magazine) ++cnt[c]; for(unsigned char c:ransomNote) if(--cnt[c]<0) return false; return true;''',
8:r'''int cnt[256]={}; for(unsigned char c:s) ++cnt[c]; int expected=0; for(int x:cnt) if(x){if(expected && x!=expected) return false; expected=x;} return true;''',
9:r'''int cnt[26]={}; for(char c:text) if(c>='a'&&c<='z') ++cnt[c-'a']; return min({cnt['b'-'a'],cnt['a'-'a'],cnt['l'-'a']/2,cnt['o'-'a']/2,cnt['n'-'a']});''',
10:r'''int cnt[256]={}; for(unsigned char c:s) ++cnt[c]; vector<pair<int,char>> items; for(int c=0;c<256;++c) if(cnt[c]) items.push_back({cnt[c],char(c)}); sort(items.begin(),items.end(),[](auto a,auto b){return a.first>b.first;}); string out; for(auto [n,c]:items) out.append(n,c); return out;''',
11:r'''int l=0,r=(int)s.size()-1; while(l<r){while(l<r&&!isalnum((unsigned char)s[l])) ++l; while(l<r&&!isalnum((unsigned char)s[r])) --r; if(tolower((unsigned char)s[l])!=tolower((unsigned char)s[r])) return false; ++l;--r;} return true;''',
12:r'''auto pal=[&](int l,int r){while(l<r) if(s[l++]!=s[r--]) return false; return true;}; int l=0,r=(int)s.size()-1; while(l<r){if(s[l]!=s[r]) return pal(l+1,r)||pal(l,r-1); ++l;--r;} return true;''',
13:r'''for(const string& w:words){bool ok=true; for(int i=0,j=(int)w.size()-1;i<j;++i,--j) if(w[i]!=w[j]){ok=false;break;} if(ok) return w;} return "";''',
14:r'''auto vowel=[](char c){return string("aeiouAEIOU").find(c)!=string::npos;}; int l=0,r=(int)s.size()-1; while(l<r){if(!vowel(s[l])){++l;continue;} if(!vowel(s[r])){--r;continue;} swap(s[l++],s[r--]);} return s;''',
15:r'''int l=0,r=(int)s.size()-1; while(l<r){if(!isalpha((unsigned char)s[l])){++l;continue;} if(!isalpha((unsigned char)s[r])){--r;continue;} swap(s[l++],s[r--]);} return s;''',
16:r'''int cnt[256]={}; if(s.size()!=t.size()) return false; for(unsigned char c:s) ++cnt[c]; for(unsigned char c:t) if(--cnt[c]<0) return false; return true;''',
17:r'''int f[256],g[256]; fill(begin(f),end(f),-1);fill(begin(g),end(g),-1); if(s.size()!=t.size()) return false; for(int i=0;i<(int)s.size();++i){unsigned char a=s[i],b=t[i]; if((f[a]!=-1&&f[a]!=b)||(g[b]!=-1&&g[b]!=a)) return false; f[a]=b;g[b]=a;} return true;''',
18:r'''istringstream in(s); vector<string> words; string w; while(in>>w) words.push_back(w); if(words.size()!=pattern.size()) return false; unordered_map<char,string> f;unordered_map<string,char> g; for(int i=0;i<(int)words.size();++i){char c=pattern[i]; if((f.count(c)&&f[c]!=words[i])||(g.count(words[i])&&g[words[i]]!=c)) return false; f[c]=words[i];g[words[i]]=c;} return true;''',
19:r'''map<string,vector<string>> groups; for(const string& s:strs){string key=s;sort(key.begin(),key.end());groups[key].push_back(s);} vector<vector<string>> out;for(auto& [key,values]:groups) out.push_back(values);return out;''',
20:r'''if(word1.size()!=word2.size()) return false; int a[26]={},b[26]={};for(char c:word1)++a[c-'a'];for(char c:word2)++b[c-'a'];for(int i=0;i<26;++i)if((a[i]==0)!=(b[i]==0))return false;sort(begin(a),end(a));sort(begin(b),end(b));return equal(begin(a),end(a),begin(b));''',
21:r'''int ans=0;for(int i=0;i+2<(int)s.size();++i)if(s[i]!=s[i+1]&&s[i]!=s[i+2]&&s[i+1]!=s[i+2])++ans;return ans;''',
22:r'''auto vowel=[](char c){return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';}; int count=0;for(int i=0;i<(int)s.size();++i){count+=vowel(s[i]);if(i>=k)count-=vowel(s[i-k]);if(i==k-1||i>=k) ans=max(ans,count);}return ans;''',
23:r'''int white=0,best=k;for(int i=0;i<(int)blocks.size();++i){white+=blocks[i]=='W';if(i>=k)white-=blocks[i-k]=='W';if(i>=k-1)best=min(best,white);}return best;''',
24:r'''if(s1.size()>s2.size())return false;int need[26]={},have[26]={};for(char c:s1)++need[c-'a'];for(int i=0;i<(int)s2.size();++i){++have[s2[i]-'a'];if(i>=(int)s1.size())--have[s2[i-s1.size()]-'a'];if(i+1>=(int)s1.size()&&equal(begin(need),end(need),begin(have)))return true;}return false;''',
25:r'''vector<int> out;if(p.size()>s.size())return out;int want[26]={},have[26]={};for(char c:p)++want[c-'a'];for(int i=0;i<(int)s.size();++i){++have[s[i]-'a'];if(i>=(int)p.size())--have[s[i-p.size()]-'a'];if(i+1>=(int)p.size()&&equal(begin(want),end(want),begin(have)))out.push_back(i+1-p.size());}return out;''',
26:r'''int last[256];fill(begin(last),end(last),-1);int left=0,best=0;for(int right=0;right<(int)s.size();++right){left=max(left,last[(unsigned char)s[right]]+1);last[(unsigned char)s[right]]=right;best=max(best,right-left+1);}return best;''',
27:r'''int cnt[26]={},left=0,best=0,top=0;for(int right=0;right<(int)s.size();++right){top=max(top,++cnt[s[right]-'A']);while(right-left+1-top>k)--cnt[s[left++]-'A'];best=max(best,right-left+1);}return best;''',
28:r'''if(t.empty())return "";int need[256]={};for(unsigned char c:t)++need[c];int missing=t.size(),left=0,start=0,best=INT_MAX;for(int right=0;right<(int)s.size();++right){unsigned char c=s[right];if(need[c]-- >0)--missing;while(missing==0){if(right-left+1<best){start=left;best=right-left+1;}unsigned char out=s[left++];if(++need[out]>0)++missing;}}return best==INT_MAX?"":s.substr(start,best);''',
29:r'''int cnt[3]={},left=0,ans=0;for(int right=0;right<(int)s.size();++right){++cnt[s[right]-'a'];while(cnt[0]&&cnt[1]&&cnt[2])--cnt[s[left++]-'a'];ans+=left;}return ans;''',
30:r'''auto best=[&](char target){int l=0,changes=0,answer=0;for(int r=0;r<(int)answerKey.size();++r){changes+=answerKey[r]!=target;while(changes>k)changes-=answerKey[l++]!=target;answer=max(answer,r-l+1);}return answer;};return max(best('T'),best('F'));''',
31:r'''unordered_map<char,int> val{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};int ans=0;for(int i=0;i<(int)s.size();++i){int v=val[s[i]];ans+=(i+1<(int)s.size()&&v<val[s[i+1]])?-v:v;}return ans;''',
32:r'''int i=0,n=s.size();while(i<n&&s[i]==' ')++i;int sign=1;if(i<n&&(s[i]=='+'||s[i]=='-'))sign=s[i++]=='-'?-1:1;long long x=0;long long limit=sign==1?INT_MAX:-(long long)INT_MIN;while(i<n&&isdigit((unsigned char)s[i])){int digit=s[i++]-'0';if(x>(limit-digit)/10)return sign==1?INT_MAX:INT_MIN;x=x*10+digit;}return (int)(sign*x);''',
33:r'''vector<pair<int,string>> units{{1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}};string ans;for(auto& [v,s]:units)while(num>=v){ans+=s;num-=v;}return ans;''',
34:r'''string out;int i=(int)num1.size()-1,j=(int)num2.size()-1,carry=0;while(i>=0||j>=0||carry){int sum=carry+(i>=0?num1[i--]-'0':0)+(j>=0?num2[j--]-'0':0);out+=char('0'+sum%10);carry=sum/10;}reverse(out.begin(),out.end());return out;''',
35:r'''if(num1=="0"||num2=="0")return "0";vector<int> v(num1.size()+num2.size());for(int i=(int)num1.size()-1;i>=0;--i)for(int j=(int)num2.size()-1;j>=0;--j){int k=i+j+1;int sum=(num1[i]-'0')*(num2[j]-'0')+v[k];v[k]=sum%10;v[k-1]+=sum/10;}string out;int i=0;while(i<(int)v.size()&&v[i]==0)++i;for(;i<(int)v.size();++i)out+=char('0'+v[i]);return out.empty()?"0":out;''',
36:r'''return (int)haystack.find(needle);''',
37:r'''int n=s.size();vector<int> pi(n);for(int i=1;i<n;++i){int j=pi[i-1];while(j&&s[i]!=s[j])j=pi[j-1];if(s[i]==s[j])++j;pi[i]=j;}int period=n-pi.back();return pi.back()>0&&n%period==0;''',
38:r'''vector<int> ans;if(pat.empty())return ans;vector<int> pi(pat.size());for(int i=1;i<(int)pat.size();++i){int j=pi[i-1];while(j&&pat[i]!=pat[j])j=pi[j-1];if(pat[i]==pat[j])++j;pi[i]=j;}int j=0;for(int i=0;i<(int)txt.size();++i){while(j&&txt[i]!=pat[j])j=pi[j-1];if(txt[i]==pat[j])++j;if(j==(int)pat.size()){ans.push_back(i-j+1);j=pi[j-1];}}return ans;''',
39:r'''int n=s.size();vector<int> pi(n);for(int i=1;i<n;++i){int j=pi[i-1];while(j&&s[i]!=s[j])j=pi[j-1];if(s[i]==s[j])++j;pi[i]=j;}return s.substr(0,pi.back());''',
40:r'''unordered_set<string> seen,dup;for(int i=0;i+10<=(int)s.size();++i){string part=s.substr(i,10);if(!seen.insert(part).second)dup.insert(part);}return vector<string>(dup.begin(),dup.end());''',
41:r'''int repeat=(b.size()+a.size()-1)/a.size();string built;for(int i=0;i<repeat;++i)built+=a;if(built.find(b)!=string::npos)return repeat;built+=a;return built.find(b)!=string::npos?repeat+1:-1;''',
42:r'''vector<int> ans;if(words.empty())return ans;int w=words[0].size(),total=words.size(),length=w*total;unordered_map<string,int> need;for(auto& word:words)++need[word];for(int start=0;start<w;++start){unordered_map<string,int> have;int l=start,count=0;for(int r=start;r+w<=(int)s.size();r+=w){string token=s.substr(r,w);if(!need.count(token)){have.clear();count=0;l=r+w;continue;}++have[token];++count;while(have[token]>need[token]){--have[s.substr(l,w)];l+=w;--count;}if(count==total){ans.push_back(l);--have[s.substr(l,w)];l+=w;--count;}}}return ans;''',
43:r'''auto match=[&](const string& a){if(a.size()!=pattern.size())return false;int f[256],g[256];fill(begin(f),end(f),-1);fill(begin(g),end(g),-1);for(int i=0;i<(int)a.size();++i){unsigned char x=a[i],y=pattern[i];if((f[x]!=-1&&f[x]!=y)||(g[y]!=-1&&g[y]!=x))return false;f[x]=y;g[y]=x;}return true;};vector<string> out;for(auto& w:words)if(match(w))out.push_back(w);return out;''',
44:r'''int last[26]={};for(int i=0;i<(int)s.size();++i)last[s[i]-'a']=i;vector<int> out;int begin=0,end=0;for(int i=0;i<(int)s.size();++i){end=max(end,last[s[i]-'a']);if(i==end){out.push_back(end-begin+1);begin=i+1;}}return out;''',
45:r'''if(numRows==1||numRows>=(int)s.size())return s;vector<string> rows(numRows);int row=0,step=1;for(char c:s){rows[row]+=c;if(row==0)step=1;else if(row==numRows-1)step=-1;row+=step;}string out;for(auto& part:rows)out+=part;return out;''',
}
# Adapt a few bodies to their recorded parameter names below.
O[22]='int ans=0;'+O[22]
# baseline alternatives are supplied in a separate reviewed table below.
B={
1:r'''reverse(s.begin(),s.end());''',
2:r'''string out=s;for(int i=0;i<(int)out.size();++i)if(out[i]>='A'&&out[i]<='Z')out[i]+=32;return out;''',
3:r'''istringstream in(s);string word,last;while(in>>word)last=word;return last.size();''',
4:r'''string out;for(int i=0;i<max(word1.size(),word2.size());++i){if(i<(int)word1.size())out+=word1[i];if(i<(int)word2.size())out+=word2[i];}return out;''',
5:r'''istringstream in(s);vector<string> words;string w,out;while(in>>w)words.push_back(w);for(int i=(int)words.size()-1;i>=0;--i){if(!out.empty())out+=' ';out+=words[i];}return out;''',
6:r'''for(int i=0;i<(int)s.size();++i){int count=0;for(char c:s)count+=c==s[i];if(count==1)return i;}return -1;''',
7:r'''for(char c:ransomNote){auto pos=magazine.find(c);if(pos==string::npos)return false;magazine.erase(pos,1);}return true;''',
8:r'''map<char,int> f;for(char c:s)++f[c];int n=f.begin()->second;for(auto [c,count]:f)if(count!=n)return false;return true;''',
10:r'''map<char,int> f;for(char c:s)++f[c];vector<pair<char,int>> order(f.begin(),f.end());sort(order.begin(),order.end(),[](auto a,auto b){return a.second>b.second;});string out;for(auto [c,n]:order)out.append(n,c);return out;''',
11:r'''string cleaned;for(unsigned char c:s)if(isalnum(c))cleaned+=char(tolower(c));string backwards=cleaned;reverse(backwards.begin(),backwards.end());return cleaned==backwards;''',
12:r'''auto pal=[](string a){string b=a;reverse(b.begin(),b.end());return a==b;};if(pal(s))return true;for(int i=0;i<(int)s.size();++i)if(pal(s.substr(0,i)+s.substr(i+1)))return true;return false;''',
14:r'''string vowels;for(char c:s)if(string("aeiouAEIOU").find(c)!=string::npos)vowels+=c;reverse(vowels.begin(),vowels.end());int i=0;for(char& c:s)if(string("aeiouAEIOU").find(c)!=string::npos)c=vowels[i++];return s;''',
15:r'''string letters;for(char c:s)if(isalpha((unsigned char)c))letters+=c;reverse(letters.begin(),letters.end());int i=0;for(char& c:s)if(isalpha((unsigned char)c))c=letters[i++];return s;''',
16:r'''sort(s.begin(),s.end());sort(t.begin(),t.end());return s==t;''',
19:r'''vector<vector<string>> groups;for(auto& s:strs){string key=s;sort(key.begin(),key.end());bool found=false;for(auto& group:groups){string other=group[0];sort(other.begin(),other.end());if(other==key){group.push_back(s);found=true;break;}}if(!found)groups.push_back({s});}return groups;''',
21:r'''int ans=0;for(int i=0;i+3<=(int)s.size();++i){set<char> unique(s.begin()+i,s.begin()+i+3);ans+=unique.size()==3;}return ans;''',
22:r'''int ans=0;for(int i=0;i+k<=(int)s.size();++i){int count=0;for(int j=i;j<i+k;++j)count+=string("aeiou").find(s[j])!=string::npos;ans=max(ans,count);}return ans;''',
23:r'''int ans=k;for(int i=0;i+k<=(int)blocks.size();++i){int whites=0;for(int j=i;j<i+k;++j)whites+=blocks[j]=='W';ans=min(ans,whites);}return ans;''',
24:r'''sort(s1.begin(),s1.end());for(int i=0;i+s1.size()<=s2.size();++i){string part=s2.substr(i,s1.size());sort(part.begin(),part.end());if(part==s1)return true;}return false;''',
25:r'''vector<int> ans;sort(p.begin(),p.end());for(int i=0;i+p.size()<=s.size();++i){string part=s.substr(i,p.size());sort(part.begin(),part.end());if(part==p)ans.push_back(i);}return ans;''',
26:r'''int best=0;for(int i=0;i<(int)s.size();++i){set<char> seen;for(int j=i;j<(int)s.size();++j){if(!seen.insert(s[j]).second)break;best=max(best,j-i+1);}}return best;''',
27:r'''int best=0;for(int i=0;i<(int)s.size();++i){int cnt[26]={},highest=0;for(int j=i;j<(int)s.size();++j){highest=max(highest,++cnt[s[j]-'A']);if(j-i+1-highest<=k)best=max(best,j-i+1);}}return best;''',
28:r'''string best="";for(int i=0;i<(int)s.size();++i)for(int j=i;j<(int)s.size();++j){string part=s.substr(i,j-i+1);int cnt[256]={};for(unsigned char c:part)++cnt[c];bool ok=true;for(unsigned char c:t)if(--cnt[c]<0){ok=false;break;}if(ok&&(best.empty()||part.size()<best.size()))best=part;}return best;''',
29:r'''int ans=0;for(int i=0;i<(int)s.size();++i){bool seen[3]={};for(int j=i;j<(int)s.size();++j){seen[s[j]-'a']=true;if(seen[0]&&seen[1]&&seen[2])++ans;}}return ans;''',
30:r'''int ans=0;for(int i=0;i<(int)answerKey.size();++i){int t=0,f=0;for(int j=i;j<(int)answerKey.size();++j){t+=answerKey[j]=='T';f+=answerKey[j]=='F';if(min(t,f)<=k)ans=max(ans,j-i+1);}}return ans;''',
36:r'''for(int i=0;i+needle.size()<=haystack.size();++i)if(haystack.compare(i,needle.size(),needle)==0)return i;return -1;''',
37:r'''for(int width=1;width*2<=s.size();++width){if(s.size()%width)continue;bool ok=true;for(int i=width;i<(int)s.size();++i)if(s[i]!=s[i%width]){ok=false;break;}if(ok)return true;}return false;''',
38:r'''vector<int> ans;for(int i=0;i+pat.size()<=txt.size();++i)if(txt.compare(i,pat.size(),pat)==0)ans.push_back(i);return ans;''',
39:r'''for(int length=(int)s.size()-1;length>0;--length)if(s.compare(0,length,s,s.size()-length,length)==0)return s.substr(0,length);return "";''',
40:r'''vector<string> out;for(int i=0;i+10<=s.size();++i){string sub=s.substr(i,10);if(find(out.begin(),out.end(),sub)!=out.end())continue;for(int j=i+1;j+10<=s.size();++j)if(s.substr(j,10)==sub){out.push_back(sub);break;}}return out;''',
42:r'''vector<int> ans;if(words.empty())return ans;int len=words.size()*words[0].size();map<string,int> required;for(auto& w:words)++required[w];for(int i=0;i+len<=s.size();++i){auto remain=required;int j=0;for(;j<len;j+=words[0].size()){auto token=s.substr(i+j,words[0].size());if(remain[token]--<=0)break;}if(j==len)ans.push_back(i);}return ans;''',
45:r'''if(numRows==1)return s;vector<string> rows(numRows);for(int i=0;i<(int)s.size();++i){int period=2*numRows-2,x=i%period;int row=min(x,period-x);rows[row]+=s[i];}string out;for(auto& row:rows)out+=row;return out;''',
}
# A problem with no meaningful separate intermediate may reuse the efficient implementation.
# The written solution note must be explicit about that choice.
BETTER={
6:r'''unordered_map<char,int> freq;for(char c:s)++freq[c];for(int i=0;i<(int)s.size();++i)if(freq[s[i]]==1)return i;return -1;''',
10:r'''unordered_map<char,int> freq;for(char c:s)++freq[c];priority_queue<pair<int,char>> heap;for(auto [c,n]:freq)heap.push({n,c});string out;while(!heap.empty()){auto [n,c]=heap.top();heap.pop();out.append(n,c);}return out;''',
16:r'''unordered_map<char,int> freq;if(s.size()!=t.size())return false;for(char c:s)++freq[c];for(char c:t)if(--freq[c]<0)return false;return true;''',
19:r'''unordered_map<string,vector<string>> groups;for(const string& word:strs){string key=word;sort(key.begin(),key.end());groups[key].push_back(word);}vector<vector<string>> out;for(auto& entry:groups)out.push_back(entry.second);return out;''',
22:r'''vector<int> prefix(s.size()+1);for(int i=0;i<(int)s.size();++i)prefix[i+1]=prefix[i]+(string("aeiou").find(s[i])!=string::npos);int ans=0;for(int i=k;i<(int)prefix.size();++i)ans=max(ans,prefix[i]-prefix[i-k]);return ans;''',
23:r'''vector<int> prefix(blocks.size()+1);for(int i=0;i<(int)blocks.size();++i)prefix[i+1]=prefix[i]+(blocks[i]=='W');int best=k;for(int i=k;i<(int)prefix.size();++i)best=min(best,prefix[i]-prefix[i-k]);return best;''',
24:r'''int need[26]={};for(char c:s1)++need[c-'a'];for(int i=0;i+s1.size()<=s2.size();++i){int have[26]={};for(int j=0;j<(int)s1.size();++j)++have[s2[i+j]-'a'];if(equal(begin(need),end(need),begin(have)))return true;}return false;''',
25:r'''vector<int> out;int need[26]={};for(char c:p)++need[c-'a'];for(int i=0;i+p.size()<=s.size();++i){int have[26]={};for(int j=0;j<(int)p.size();++j)++have[s[i+j]-'a'];if(equal(begin(need),end(need),begin(have)))out.push_back(i);}return out;''',
26:r'''unordered_set<char> seen;int left=0,best=0;for(int right=0;right<(int)s.size();++right){while(seen.count(s[right]))seen.erase(s[left++]);seen.insert(s[right]);best=max(best,right-left+1);}return best;''',
27:r'''int count[26]={},left=0,best=0;for(int right=0;right<(int)s.size();++right){++count[s[right]-'A'];while(true){int highest=*max_element(begin(count),end(count));if(right-left+1-highest<=k)break;--count[s[left++]-'A'];}best=max(best,right-left+1);}return best;''',
37:r'''return (s+s).substr(1,2*s.size()-2).find(s)!=string::npos;''',
40:r'''unordered_map<string,int> freq;vector<string> out;for(int i=0;i+10<=(int)s.size();++i){string part=s.substr(i,10);if(++freq[part]==2)out.push_back(part);}return out;''',
}


def write_reference(path, content, previous_generated=None):
    if path.exists():
        old=path.read_text()
        if old==content:
            return
        if 'DETAILED BEGINNER EXPLANATION' in old:
            return  # Preserve the already formatted reference and any later edits.
        if 'REFERENCE SLOT INTENTIONALLY EMPTY' not in old and old != previous_generated:
            raise RuntimeError(f'Refusing to overwrite an authored reference: {path}')
    path.write_text(content)


def build():
    manifest=json.loads((MODULE/'problem_manifest.json').read_text())
    manifest=[item for item in manifest if item['index'] <= 45]
    assert len(manifest)==45 and set(O)==set(range(1,46))
    for item in manifest:
        index=item['index']; folder=ROOT/item['folder']; signature=item['signature']
        for filename,body in [('02_brute_force.cpp',B.get(index,O[index])),
                              ('03_better_approach.cpp',BETTER.get(index,O[index])),
                              ('04_optimal_solution.cpp',O[index])]:
            code=f'#include <bits/stdc++.h>\nusing namespace std;\n\nclass Solution {{\npublic:\n    {signature} {{\n        {body}\n    }}\n}};\n'
            fallback=f'#include <bits/stdc++.h>\nusing namespace std;\n\nclass Solution {{\npublic:\n    {signature} {{\n        {O[index]}\n    }}\n}};\n'
            write_reference(folder/filename,code, fallback if filename=='03_better_approach.cpp' else None)
        if not (folder/'solution.md').exists():
            kinds=['direct baseline' if index in B else 'same efficient approach (no distinct baseline recorded)',
                   'intermediate alternative' if index in BETTER else 'same efficient approach (no distinct intermediate recorded)',
                   'efficient reference']
            (folder/'solution.md').write_text(f'''# {item['title']} — reference discussion

## Contract

`{signature}` — [{item['platform']} problem]({item['url']}). Verify the current live editor's signature before submission.

## Recognition cue

{item['goal']}

## Approach progression

| File | Role |
|---|---|
| [Brute force](02_brute_force.cpp) | {kinds[0]} |
| [Better](03_better_approach.cpp) | {kinds[1]} |
| [Optimal](04_optimal_solution.cpp) | {kinds[2]} |

The levels are comparison slots; a separate intermediate algorithm is not invented when it would only duplicate another method. Work through the first case in `testcases.md` by hand, tracking the state named in the code. The input contract and edge cases in the live statement take precedence over example formatting here.

Reference availability is separate from your own original attempt and revision history.
''')
    print('Prepared 45 String problems with three compilable reference files each.')


if __name__=='__main__':
    build()
