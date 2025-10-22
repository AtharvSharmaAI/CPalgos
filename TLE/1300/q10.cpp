#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll bis(vector<ll> &b, ll a){
    int l = 0;
    int r = b.size()-1;
    while(l<r){
        int m = l +(r-l)/2;
        if(b[m]+1 >= a) r = m;
        else l = m+1;
    }
    
    return l;
}


void solve(){
    int n;
    cin >> n;
    vector<ll> a(n),b;
    for(int i = 0;i<n;i++){
        cin >> a[i];
        if(a[i] < i+1){
            b.push_back(i);
        }
    }
    ll count = 0;
    for(int i = 0 ; i<b.size();i++){
        count += bis(b,a[b[i]]);
    }
    cout << count << endl;
    
    
}


int main(){
    int t;
    cin >> t;
    while(t--) solve();
}