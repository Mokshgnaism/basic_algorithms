#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>dp;
int n;
bool possible(vector<int>&a,int i,int sum){
    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }
    if(i>=n){
        return false;
    }
    if(sum<0){
        return false;
    }
    if(sum==0){
        return true;
    }
    int ab = possible(a,i+1,sum-a[i]);
    int ex = possible(a,i+1,sum);
    return dp[i][sum]=ab||ex;
}
void backtrack(vector<int>&a,int i,int sum,vector<int>path){
    if(sum==0){
        for(auto el:path)cout<<el<<" ";
        cout<<endl;
        return ;
    }
    if(sum<0||i>=n){
        return ;
    }

    if(sum>=a[i]&&dp[i+1][sum-a[i]]){
        path.push_back(a[i]);
        backtrack(a,i+1,sum-a[i],path);
        path.pop_back();
    }

    if(dp[i+1][sum]){
        backtrack(a,i+1,sum,path);
    }

}
int32_t main() {
    // Your code here
    cin>>n;
    vector<int>a(n);
    int sum;cin>>sum;int tot = 0;
    for(auto &x:a){cin>>x;tot+=x;}
    dp = vector<vector<int>>(n+1,vector<int>(sum+1,-1));
    cout<<possible(a,0,sum)<<endl;

    if(possible(a,0,sum)){
        vector<int>path;
        backtrack(a,0,sum,path);
    }else{
        cout<<"No"<<endl;
    }

    return 0;
}