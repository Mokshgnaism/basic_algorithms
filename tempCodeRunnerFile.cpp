#include <bits/stdc++.h>
using namespace std;
#define int long long
class Node{
    public:
    int val;
    Node*right;
    Node*left;
    Node(int val){
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

//tree vertex splitting using dfs 
set<int>s;
// vector<int>dist(1000);
map<Node*,int>dist;
int t;
map<Node*,Node*>parent;
map<pair<Node*,Node*>,int>w;

void dfs_r(Node*root){
    if(root==NULL){
        return;
    }
    if(root->left){
        parent[root->left]=root;
        dfs_r(root->left);
    }
    if(root->right){
        parent[root->right]=root;
        dfs_r(root->right);
    }
}

int tvs(Node*root){
    if(root==NULL){
        return 0;
    }
    dist[root]=0;
 if(root->left)
        dist[root] = max(dist[root],tvs(root->left)+w[{root,root->left}]);

 if(root->right)
        dist[root] = max(dist[root],tvs(root->right)+w[{root,root->right}]);

    if(parent[root]!=NULL&&dist[root]+w[{root,parent[root]}]>t){
        s.insert(root->val);
        dist[root]=0;
    }
    return dist[root];

}

int32_t main() {
    // Your code here
    cin>>t;
    Node*root;
  
    queue<Node*>q;
    int val;
    cin>>val;
    root = new Node(val);
    parent[root] = NULL;
    q.push(root);
    while(!q.empty()){
        Node*top = q.front();
        q.pop();
        int left;
        int left_wt;
        int right;;
        cin>>left;
        cin>>left_wt;
        int right_wt;
        cin>>right;
        cin>>right_wt;
        if(left!=-1){
            Node*temp = new Node(left);
            w[{temp,top}] = left_wt;
            w[{top,temp}] = left_wt;
            top->left = temp;
            q.push(temp);
        }
        if(right!=-1){
            
            Node*temp = new Node(right);
            top->right = temp;
            w[{temp,top}] = right_wt;
            w[{top,temp}] = right_wt;
            q.push(temp);
        }
    }

    dfs_r(root);
    tvs(root);
    cout<<s.size()<<" ";
    for(auto idx : s){
        cout<<idx<<" ";
    }
    for (const pair<Node*, int>& p : dist) {
        cout << "Node " << p.first->val << ": " << p.second << "\n";
    }
    cout<<endl;
    return 0;
}