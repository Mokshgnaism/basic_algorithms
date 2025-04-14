#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int n;
    cin>>n;
    vector<vector<int>>a(n,vector<int>(n,0));
    // a[0][n/2]=1;
    int i=0;
    int j =(n-1)/2;
    int next = 2;
    a[i][j]=1;
    for(int key = 2;key<=n*n;key++){
        int next_row = (i-1+n)%n;
        int next_col = (j-1+n)%n;
        if(a[next_row][next_col]!=0){
            i = (i+1)%n;
        }else{
            i = next_row;
            j = next_col;
        }
        a[i][j]=key;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}