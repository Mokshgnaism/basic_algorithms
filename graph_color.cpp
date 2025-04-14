#include <bits/stdc++.h>
using namespace std;
#define int long long
int mini = INT_MAX;
// int n;
map<int,list<int>>adj;


bool ispossible(int idx,vector<int>&color,int col){
    for(auto kid:adj[idx]){
        if(color[kid]==col)return false;
    }
    return true;
}
void backtrack(int idx,int n,vector<int>&color,int x){
    if(idx>n){
        mini = min(mini,x);
        return ;
    }
    for(int i=1;i<=x;i++){
        if(ispossible(idx,color,i)){
            color[idx]=i;
            backtrack(idx+1,n,color,x);
            color[idx]=0;
        }
    }
    if (ispossible(idx, color, x + 1)) {
        color[idx] = x + 1;
        backtrack(idx + 1, n,color, x + 1);
        color[idx] = 0;
    }
}


void fill_color(int n,int node,int cromatic_number,vector<int>&col){
    if(node>n){
        for(int i=1;i<=n;i++)cout<<col[i]<<" ";
        cout<<endl;
        return ;
    }
    for(int i=1;i<=cromatic_number;i++){
        if(ispossible(node,col,i)){
            col[node]  = i;
            fill_color(n,node+1,cromatic_number,col);
            col[node]=0;
        }
    }

}

int32_t main() {
    int n;
    cin>>n;
    vector<int>color = vector<int>(n+1,0);
    int e;cin>>e;
    for(int i=0;i<e;i++){
        int u;
        int v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    backtrack(1,n,color,1);
    cout<<mini<<endl;
    vector<int>col(n+1,0);
    fill_color(n,1,mini,col);
    return 0;
}