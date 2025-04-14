#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int n = 3;
    int wt = 50;

    vector<int> price = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    vector<pair<double, int>> mpp;
    for(int i=0;i<n;i++){
        double ratio = price[i]*1.0/weight[i];
        mpp.push_back(make_pair(ratio,i));
    }
    sort(mpp.rbegin(),mpp.rend());
    int idx = 0;
    int rem = wt;
    double profit = 0;
    vector<double>soln(n,0);
    while(rem>0&&idx<n){
        int next_idx = mpp[idx].second;
        int rat = mpp[idx].first;
        int wt_item = weight[next_idx];
        if(wt_item<=rem){
            rem = rem - wt_item;
            soln[next_idx]=1;
            profit+=price[next_idx];
        }else{
            profit += rat*(rem);
            soln[next_idx]=((rem*1.0)/wt_item);
            rem = 0;
        }
        idx++;
    }
    for(int i=0;i<n;i++){
        cout<<soln[i]<<" ";
    }
    cout<<endl<<profit<<endl;
    return 0;
}