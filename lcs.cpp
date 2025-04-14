#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>dp;
vector<vector<int>>dir;
int lcs(string s1,string s2){
    int n = s1.size();int m = s2.size();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
                dir[i][j]= 1;
            }else if(dp[i-1][j]>=dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
                dir[i][j] = 2;
            }else{
                dp[i][j]=dp[i][j-1];
                dir[i][j] = 3;
            }
        }
    }
    int i = n;
    int j = m;
    string s3;
    while(i>=1&&j>=1){
        if(dir[i][j]==1){
            s3+=s1[i-1];
            i--;
            j--;
        }if(dir[i][j]==2){
            i=i-1;
        }else if(dir[i][j]==3){
            j = j-1;
        }
    }
    reverse(s3.begin(),s3.end());
    cout<<s3<<endl;
    return dp[n][m];
}
int32_t main() {
    // Your code here
    string s1 = "aabcde";
    string s2 = "abcde";
    int n = s1.size();
    int m = s2.size();
    dp = vector<vector<int>>(n+1,vector<int>(m+1,0));
    dir = vector<vector<int>>(n+1,vector<int>(m+1,0));
    int len = lcs(s1,s2);
    cout<<len<<endl;
    return 0;
}