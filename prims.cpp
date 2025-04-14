#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    // Your code here
    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<bool>inmst(n+1,false);
    // inmst[1]=true;
    vector<vector<int>>c(n+1,vector<int>(n+1,INT_MAX));
    vector<int>dist(n+1,INT_MAX);
    dist[1]=0;
    vector<int>parent(n+1,-1);
    map<int,list<int>>adj;
    parent[1]=1;


    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        c[u][v]=w;
        c[v][u] = w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int key=1;key<=n;key++){
        int min_dist_idx = -1;
        int min_dist = INT_MAX;
        for(int i=1;i<=n;i++){
            if(dist[i]<min_dist&&!inmst[i]){
                min_dist_idx = i;
                min_dist = dist[i];
            }
        }
        if(min_dist_idx==-1){
            break;
        }
        inmst[min_dist_idx]=true;
        for(auto kid:adj[min_dist_idx]){
            if(!inmst[kid]&&dist[kid]>c[kid][min_dist_idx]){
                parent[kid]=min_dist_idx;
                dist[kid]=c[kid][min_dist_idx];
            }
        }
    }

    for(int i=2;i<=n;i++){
        cout<<parent[i]<<"->"<<i<<endl;
    }



    return 0;
}