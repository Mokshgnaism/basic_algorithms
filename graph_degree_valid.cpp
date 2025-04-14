#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
bool ispossible(vector<int>&degree){
    for(int i=0;i<n;i++){
        int deg = degree[i];
        int idx = i+1;
        while(deg>0&&idx<n){
            degree[idx]--;
            if(degree[idx]<0)return false;
            deg--;
            idx++;
        }
        if(deg>0&&idx>n)return false;
    }
    return true;
}
int32_t main() {
    cin>>n;
    return 0;
}