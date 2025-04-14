#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    map<int,list<int>>adj;
    int n,e,src;
    cin>>n>>e>>src;
    set<pair<int,int>>s;
    vector<int>dist(n+1,INT_MAX);
    vector<vector<int>>c(n+1,vector<int>(n+1,INT_MAX));

    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(v);
        c[u][v]=w;
    }

    dist[src]=0;

    for(int i=1;i<n;i++){
        if(i!=src){
            s.insert({INT_MAX,i});
        }
    }

    s.insert({0,src});
    while(!s.empty()){

        pair<int,int>p = *s.begin();
        int wt = p.first;
        int node = p.second;
        s.erase(s.begin());
        for(auto kid :adj[node]){
            int dist_kid = dist[kid];
                if(dist_kid > dist[node]+c[node][kid]){
                    s.erase({dist_kid,kid});
                    dist[kid] = dist[node]+c[node][kid];
                    s.insert({dist[kid],kid});
                }
        }
    }
    for(int i=1;i<dist.size();i++){
        cout<< i << " == "<<dist[i]<<" "<<endl;
    }
    // Your code here
    return 0;
}