#include <bits/stdc++.h>
using namespace std;
#define int long long
class dsu{
    public:
    int n;
    vector<int>parent;
    vector<int>rank;
    dsu(int n){
        parent = vector<int>(n+1,0);
        rank = vector<int>(n+1,0);
        for(int i=1;i<=n;i++)parent[i]=i;
    }
    int find_parent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=find_parent(parent[node]);
    }
    void add_edge(int u,int v){
        u = find_parent(u);
        v = find_parent(v);
        int rank_u = rank[u];
        int rank_v = rank[v];
        if(rank_u<rank_v){
            parent[u]=v;
        }
        else if(rank_v<rank_u){
            parent[v]=u;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
};
bool cmp(vector<int>&a,vector<int>&b){
    return a[2]<b[2];
}
int32_t main() {
    int n;
    cin>>n;
    int e;
    cin>>e;//let it be this -> this reprresents total numberr of nodes not number of edges 
    vector<vector<int>>edges(n,vector<int>(3));
    for(int i=0;i<n;i++){
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }
    sort(edges.begin(),edges.end(),cmp);
    int filled = 0;
    dsu d(e);
    vector<pair<int,int>>connect;
    for(int i=0;i<edges.size()&&filled<n;i++){
        int parent_u = d.parent[edges[i][0]];
        int parent_v = d.parent[edges[i][1]];
        if(parent_u!=parent_v){
            d.add_edge(edges[i][0],edges[i][1]);
            connect.push_back({edges[i][0],edges[i][1]});
            filled++;
        }
    }
    sort(connect.begin(),connect.end());
    for(int i=0;i<connect.size();i++){
        cout<<connect[i].first<<"--"<<connect[i].second<<endl;
    }
    return 0;
}