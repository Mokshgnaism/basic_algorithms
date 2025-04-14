#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    // Your code here
    int n ;
    cin>>n;
    int e;
    cin>>e;
    
    map<int,list<int>>adj;
    vector<vector<int>>c(n+1,vector<int>(n+1,INT_MAX));
    vector<int>dist(n+1,INT_MAX);
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(v);
        c[u][v]=w;
    }
    
    dist[n] = 0;
    for(int i=n-1;i>=1;i--){
        for(auto next : adj[i]){
            if(dist[i]>dist[next]+c[i][next]){
                dist[i] = dist[next]+c[i][next];
            }
        }
    }
    cout<<dist[1]<<endl;
    return 0;
}