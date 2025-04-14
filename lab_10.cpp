#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<int>a;
vector<vector<int>>dp;
int solve(int idx,int diff){
    if(idx>=n){
        return abs(diff);
    }
    if(dp[idx][diff]!=-1)return dp[idx][diff];
    //take into b
    int b = INT_MAX;
    if(diff-2*a[idx]>=0)
        b = solve(idx+1,diff-2*a[idx]);
    // remain in a 
    int c = solve(idx+1,diff);
    return dp[idx][diff]=min(b,c);
}
int mini ;;
int req;
set<vector<int>>s;
void back_track(int i,int tot,vector<int>b){//here tot is like diff . 
    if(tot==mini||i>=n){
        for(int i=0;i<n;i++){
            int sum_b = accumulate(b.begin(),b.end(),0);
            if(sum_b==req){
                s.insert(b);
            }
        }
        return ;
    }
    if(tot>=2*a[i]){
        if(dp[i+1][tot-2*a[i]]==mini){
            b.push_back(a[i]);
            back_track(i+1,tot-2*a[i],b);
            b.pop_back();
        }
    }
    if(dp[i+1][tot]==mini){
        back_track(i+1,tot,b);
    }
}
int32_t main() {
    cin>>n;
    a = vector<int>(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int sum = accumulate(a.begin(),a.end(),0);
    dp = vector<vector<int>>(n+1,vector<int>(sum+1,-1));
    cout<<solve(0,sum)<<endl;
    mini = solve(0,sum);
    req = sum-mini;
    req/=2;
    vector<int>path;
    back_track(0,sum,path);
    for(auto v:s){
        for(auto i:v)cout<<i<<" ";
        cout<<endl;
    }

    return 0;
}