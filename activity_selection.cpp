#include <bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(pair<pair<int,int>,int>&a,pair<pair<int,int>,int>&b){
    return a.first.second<b.first.second;
}
int32_t main() {
    int n;
    cin>>n;
    vector<pair<pair<int,int>,int>>ac(n);
    for(int i=0;i<n;i++){
        cin>>ac[i].first.first>>ac[i].first.second;
        ac[i].second = i;
    }
    sort(ac.begin(),ac.end(),cmp);
    int  included = 1;
    int curr = 0;
    vector<int>soln;
    soln.push_back(ac[0].second);
    for(int i=1;i<ac.size();i++){
        if(ac[i].first.first>=ac[curr].first.second){
            curr = i;
            included++;
            soln.push_back(ac[i].second);
        }
    }
    cout<<included<<endl;
    for(auto idx : soln){
        cout<<idx<<" ";
    }
    return 0;
}