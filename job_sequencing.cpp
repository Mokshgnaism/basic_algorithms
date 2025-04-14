#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    vector<pair<int,int>>jobs;
    int n;
    cin>>n;
    jobs = vector<pair<int,int>>(n);
    int maxi = -1;
    for(int i=0;i<n;i++){
        cin>>jobs[i].first;
        cin>>jobs[i].second;
        maxi = max(maxi,jobs[i].second);
    }
    jobs.sort(jobs.rbegin(),jobs.rend());
    int profit = 0;
    int no =0;
    vector<int>deadlines(maxi+1,0);
    for(int i=0;i<jobs.size();i++){
        int price = jobs[i].first;
        int deadline = jobs[i].second;
        bool acc = false;
        for(int d = deadline;d>=1;d--){//assuming d can be done only from 0 to 1 and cant be completed at instant of 0 
            if(deadlines[d]==0){
                deadlines[d]=1;
                acc = true;
                no++;
                break;
            }
        }
        if(acc){
            profit +=price;
        }
    }
    cout<<no<<" -> "<<profit<<endl;
    return 0;
}