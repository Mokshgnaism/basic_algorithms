#include <bits/stdc++.h>
using namespace std;
#define int long long
map<int,list<int>>adj;
map<int,list<int>>rev;
int n;
void dfs(int node, stack<int>&st,vector<bool>&vis){
    vis[node]=true;
    for(auto kid :adj[node]){
        if(!vis[kid]){
            dfs(kid,st,vis);
        }
    }
    st.push(node);
}
vector<vector<int>>scc;
void reverse_dfs(int node,vector<bool>&vis,vector<int>&component){
    vis[node]=true;
    component.push_back(node);
    for(auto kid : rev[node]){
        if(!vis[kid]){
            reverse_dfs(kid,vis,component);
        }
    }
}

void construct(stack<int>&st){
    vector<bool>vis(n+1,0);
    while(!st.empty()){
        // int top = st.to
        if(vis[st.top()]){
            st.pop();
            continue;
        }
        int i = st.top();
        st.pop();
        vector<int>component;
        if(!vis[i]){
            reverse_dfs(i,vis,component);
        }
        scc.push_back(component);
    }
}
map<int,set<int>>gcc;

void construct_gcc(){
    int sz = scc.size();//no of connected components;
    vector<int>scc_id(n+1,0);
    for(int i=0;i<sz;i++){
        for(auto idx : scc[i]){
            scc_id[idx] = i+1;
        }
    }
    for(int i=0;i<sz;i++){
        for(auto node: scc[i]){
            for(auto kid:adj[node]){
                if(scc_id[kid]!=scc_id[node]){
                    gcc[scc_id[node]].insert(scc_id[kid]);
                }
            }
        }
    }
}

int32_t main() {
    // Your code here
    stack<int>st;
    cin>>n;
    int e;
    cin>>e;
    for(int i=0;i<e;i++){
        int u;
        int v;
        cin>>u>>v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }
    vector<bool>vis(n+1,false);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,st,vis);
        }
    }
    construct(st);
    construct_gcc();
    for(int i=0;i<scc.size();i++){
        cout<<i+1<<" -> ";
        for(auto node:scc[i]){cout<<node<<" ";}
        cout<<endl;
    }
    cout<<endl<<endl;
    for(int i=1;i<=scc.size();i++){
        if(gcc[i].size()>0){
            cout<<i<<"->";
            for(auto kid : gcc[i]){cout<<kid<<" ";}
            cout<<endl;
        }
    }

    return 0;
}