#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct treenode{
    int pos;
    char col ;
    vector<treenode *> child;
    
    treenode(int p , char c): pos(p) , col(c), child({}){};
};

treenode* construct(vector<int>&p ,string s){
    treenode *root = new treenode(1,s[0]);
    vector<treenode *> tree;
    tree.push_back(root);
    for(int i = 0 ; i<p.size() ; i++){
        treenode *node = new treenode(i+2,s[i+1]);
        tree.push_back(node);
        (tree[p[i]-1]->child).push_back(node);
    }
    return root;
}

int sub(treenode* root , int &co ){
    if(root == nullptr) return 3456;
    if((root->child.empty())) return (root->col == 'W')?(1):(-1);
    int y = (root->col == 'W')?(1):(-1);
    for(auto e:root->child){
        y += sub(e,co);
    }
    if(y==0) co++;
    //cout << y << endl;
    return y;
}

void solve(){
    int n;
    cin >> n;
    vector<treenode *> tree;
    vector<int> p(n-1,0);
    string s;
    for(int i =0;i<n-1;i++) cin >> p[i];
    cin >> s;
    treenode *root = construct(p,s);
    int c = 0;
    sub(root,c);
    cout << c << endl;
    
}


int main(){
    int t;
    cin >> t;
    while(t--) solve();
}