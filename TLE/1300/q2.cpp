// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

vector<int> binsea(int l ,int r , vector<int> &a,vector<int> &s){
    int p = 0;
    int q = s.size()-1;
    int u = -1;
    int v = -1;
    int e = q;
    while(p<q){
        int m = (p+q)/2;
        if(s[m] <= l) p = m+1;
        else if(s[m] > l){
            q = m;
            u = s[m];
            e = m;
        }
    }
    p = 0;
    q = s.size()-1;
    if(r<s[e] || l>=s[e]) return {-1,-1};
    else return {l,s[e]};
    
}


void solve(){
    int n ;
    cin >> n ;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int q ;
    cin >> q;
    vector<pair<int,int>> w(q);
    int u = -1;
    vector<int> s;
    for(int i = 0 ;i<n;i++){
        if(u!= a[i]){
            s.push_back(i+1);
            u = a[i];
        }
    }
    
    for(int i =0 ;i<q;i++){
        cin >> w[i].first >> w[i].second;
        vector<int> er = binsea(w[i].first,w[i].second,a,s);
        cout << er[0] << ' ' << er[1] << endl;
    }
    
    cout << endl;
    
    
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t ;
    while(t--){
        solve();
    }
}