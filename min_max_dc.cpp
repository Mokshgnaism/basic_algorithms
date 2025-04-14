#include <bits/stdc++.h>
using namespace std;
#define int long long
pair<int,int> min_max(vector<int>&a,int i,int j){
    if(i==j){
        return {a[i],a[i]};
    }
    if(i==j-1){
        return {max(a[i],a[j]),min(a[i],a[j])};
    }
    int mid = i+ (j-i)/2;
    pair<int,int>first = min_max(a,i,mid);
    pair<int,int>sec = min_max (a,mid+1,j);
    int max1 = first.first;
    int max2 = sec.first;
    int min1 = first.second;
    int min2 = sec.second;
    return {max(max1,max2),min(min1,min2)};
}
int32_t main() {
    // Your code here
    vector<int>a = {90,2,3,4,5,6,7,8,9,100};
    pair<int,int>m = min_max(a,0,a.size()-1);
    cout<<m.first<<" "<<m.second<<endl;
    return 0;
}
