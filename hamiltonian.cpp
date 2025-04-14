#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>adj;
int n;
bool ispossible(vector<int>&path,int next){
    for(auto p :path){
        if(p==next)return false;
    }
    return adj[path.back()][next];
}
bool hamiltoniann(vector<int>&path){
    if(path.size()==n){
        if(adj[path.back()][1]){
            for(auto p:path)cout<<p<<" ";
            cout<<endl;
            return true;
        }else{
            return false;
        }
    }

    bool a = false;
    for(int i=1;i<=n;i++){
        if(ispossible(path,i)){
            path.push_back(i);
            a = a||hamiltoniann(path);
            path.pop_back();
        }
    }
    return a;
}
int32_t main() {
    // Your code here
    cin>>n;
    adj = vector<vector<int>>(n+1,vector<int>(n+1,0));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>adj[i][j];
        }
    }

    vector<int>path;
    path.push_back(1);
    if(hamiltoniann(path)){
    }else{
        cout<<"no"<<endl;
    }
    return 0;
}