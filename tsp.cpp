#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>c;
// vector<int>path,best_path;
set<int>s best_s;
int solve(int n,set<int>s){
    if(s.size()==0){
        
        return c[n][1];
    }
    int ans = INT_MAX;
    for(auto j:s){
        s.erase(j);
        // path.push_back(j);
        int local = c[n][j] + solve(j,s);

        if(local < ans){
            // best_path = path;
            ans = local;
        }
        s.insert(j);
        // path.pop_back();
    }
    return ans;
}
int32_t main() {
    int n;
    cin>>n;
    c = vector<vector<int>>(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>c[i][j];
        }
    }
    set<int>s;
    for(int i=2;i<=n;i++){
        s.insert(i);
    }
    // path = vector<int>(n+1);
    path.push_back(1);
    cout<<solve(1,s)<<endl;
    for(auto p:best_path){
        cout<<p<<" ";
    }
    return 0;
}