#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>add(vector<vector<int>>a,vector<vector<int>>b){
    int n = a.size();
    vector<vector<int>>c(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c[i][j] = a[i][j]+b[i][j];
        }
    }
    return c;
}
vector<vector<int>>sub(vector<vector<int>>a,vector<vector<int>>b){
    int n = a.size();
    vector<vector<int>>c(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c[i][j] = a[i][j]-b[i][j];
        }
    }
    return c;
}
vector<vector<int>>strassen(vector<vector<int>>a,vector<vector<int>>b){
    int n = a.size();
    if(n==1){
        return {{a[0][0]*b[0][0]}};
    }
    vector<vector<int>>a11(n/2,vector<int>(n/2,0));
    vector<vector<int>>a12(n/2,vector<int>(n/2,0));
    vector<vector<int>>a21(n/2,vector<int>(n/2,0));
    vector<vector<int>>a22(n/2,vector<int>(n/2,0));
    vector<vector<int>>b11(n/2,vector<int>(n/2,0));
    vector<vector<int>>b12(n/2,vector<int>(n/2,0));
    vector<vector<int>>b21(n/2,vector<int>(n/2,0));
    vector<vector<int>>b22(n/2,vector<int>(n/2,0));
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n/2;j++){
            a11[i][j]=a[i][j];
            a12[i][j]=a[i][j+(n/2)];
            a21[i][j]=a[i+(n/2)][j];
            a22[i][j]=a[i+(n/2)][j+(n/2)];

            b11[i][j]=b[i][j];
            b12[i][j]=b[i][j+(n/2)];
            b21[i][j]=b[i+(n/2)][j];
            b22[i][j]=b[i+(n/2)][j+(n/2)];
        }
    }
    vector<vector<int>>p = strassen(add(a11,a22),add(b11,b22));
    vector<vector<int>>q = strassen(add(a21,a22),b11);
    vector<vector<int>>r = strassen(a11,sub(b12,b22));
    vector<vector<int>>s = strassen(a22,sub(b21,b11));
    vector<vector<int>>t = strassen(add(a11,a12),b22);
    vector<vector<int>>u = strassen(sub(a21,a11),add(b11,b12));
    vector<vector<int>>v = strassen(sub(a12,a22),add(b21,b22));
    vector<vector<int>>c11 = add(add(p,s),sub(v,t));
    vector<vector<int>>c12 = add(r,t);
    vector<vector<int>>c21 = add(q,s);
    vector<vector<int>>c22 = add(add(p,r),sub(u,q));
    vector<vector<int>>ans(n,vector<int>(n));
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n/2;j++){
            ans[i][j] = c11[i][j];
            ans[i][j+(n/2)] = c12[i][j];
            ans[i+(n/2)][j] = c21[i][j];
            ans[i+(n/2)][j+(n/2)] = c22[i][j];
        }
    }
    return ans;
}

int32_t main() {
    vector<vector<int>> a = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<vector<int>> b = {
        {16, 15, 14, 13},
        {12, 11, 10, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    };

    vector<vector<int>> result = strassen(a, b);

    for (auto &row : result) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
