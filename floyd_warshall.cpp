#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> floydwarshall(vector<vector<int>>adj){
    int n = adj.size()-1;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(adj[i][k]!=INT_MAX&&adj[k][j]!=INT_MAX)
                adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }
    return adj;
}
int32_t main() {
    // Your code here
    int n;
    cin>>n;
    vector<vector<int>>adj(n+1,vector<int>(n+1,INT_MAX));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            if(x!=-1)
                adj[i][j]=x;
        }
    }
    vector<vector<int>>ans = floydwarshall(adj);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}