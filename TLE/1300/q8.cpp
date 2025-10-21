#include<bits/stdc++.h>
using namespace std;

int maxc(int n, vector<int> &a){
    int l = 0;
    int r = n-1;
    while(l<r){
        int m = l+ (r-l)/2;
        if(a[m] == n-m-1) return m+1;
        else if(a[m] > n-m-1) r = m-1;
        else l = m+1;
    }
    return r;
}


void solve(){
    int n;
    cin >> n;
    vector<int> a(n),b;
    for(int i = 0 ;i<n;i++) cin >> a[i];
    for(int i = 1 ;i<=n ;i++){
        b.push_back(maxc(i,a));
    }
    for(auto e:b) cout << e << ' ';
    cout << endl;
}


int main(){
    int t;
    cin >> t;
    while(t--) solve();
}