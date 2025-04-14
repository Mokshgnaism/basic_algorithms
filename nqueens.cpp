#include <bits/stdc++.h>
using namespace std;
#define int long long
bool ispossible(vector<int>path,int val){
    int row = val;
    int col = path.size();
    for(int i = 0;i<path.size();i++){
        if(abs(i-col)==abs(row-path[i]))return false;
        if(path[i]==val)return false;
    }
    return true;
}
void nquuens(int n,vector<int>path){
    if(path.size()>=n){
        for(auto i:path)cout<<i<<" ";
        cout<<endl;
        return ;
    }
    for(int key = 1;key<=n;key++){
        if(ispossible(path,key)){
            path.push_back(key);
            nquuens(n,path);
            path.pop_back();
        }
    }

}
int32_t main() {
    // Your code here
    vector<int>path;
    nquuens(16,path);
    return 0;
}