#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>dp;
vector<vector<int>>pos;
int solve(vector<pair<int,int>>a,int i,int j){
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(i==j){
        return 0;
    }
    int ans = INT_MAX;
    for(int k=i;k<j;k++){
        int p1 ;
        int p2;
        int p3;
        p3 = a[k].second;
        p2 = a[i].first;
        p1 = a[j].second;
        int local = solve(a,i,k)+solve(a,k+1,j)+p1*p2*p3;
        if(local<=ans){
            ans = local;
            pos[i][j] = k;
        }
    }
    return dp[i][j]=ans;
}
void construct(int i,int j){
    if(i==j){
        cout<<"A"<<i;
        return;
    }
    int nextpos = pos[i][j];
    cout<<"(";
    construct(i,nextpos);
    construct(nextpos+1,j);
    cout<<")";
}
int32_t main() {
    int n;
    cin>>n;
    vector<pair<int,int>>a(n+1);
    dp = vector<vector<int>>(n+1,vector<int>(n+1,-1));
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    pos =  vector<vector<int>>(n+1,vector<int>(n+1));
    cout<<solve(a,1,n)<<endl;
    construct(1,n);
    return 0;
}