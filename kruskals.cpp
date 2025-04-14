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
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
    }
    int find_parent(int v){
        if(v==parent[v]){
            return v;
        }
        return parent[v] = find_parent(parent[v]);
    }
    void add_edge(int u,int v){
        int ru = rank[find_parent(u)];
        int rv = rank[find_parent(v)];
        u = find_parent(u);
        v = find_parent(v);
        if(ru<rv){
            parent[u]=v;
        }
        else if(rv<ru){
            parent[v]=u;
        }else{
            parent[v]=u;
            rank[u]++;
        }
    }
};
int32_t main() {
    // Your code here
    return 0;
}