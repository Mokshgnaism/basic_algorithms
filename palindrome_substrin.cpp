#include <bits/stdc++.h>
using namespace std;
#define int long long
string s1;
bool ispossible(string s1){
    return s1 == string(s1.rbegin(),s1.rend());
}
void solve(string s1,int i,string temp,vector<string>words){
    if(i>=s1.size()){
        int len = 0;
        for(auto word:words)len+=word.size();
        if(len == s1.size())
            for(auto word:words)cout<<word<<" ";
        cout<<endl;
        return ;
    }
    temp += s1[i];
    if(ispossible(temp)){
        words.push_back(temp);
        solve(s1,i+1,"",words);
        words.pop_back();
    }
    solve(s1,i+1,temp,words);
}
int32_t main() {
    cin>>s1;
    vector<string>words;
    solve(s1,0,"",words);
    // Your code here
    return 0;
}