#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll hcf(ll a ,ll b){
    if(b==0) return a;
    else return hcf(b, a%b);
}


void bitc(vector<ll> &a , unordered_map<ll,ll> &m){
    for(auto e:a){
        ll i = 0;
        while(e>0){
            if(e%2==1) m[i]++;
            e = e/2;
            i++;
        }
    }
}


void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i =0;i<n;i++) cin >> a[i];
    unordered_map<ll,ll> m;
    bitc(a,m);
    ll mn = INT_MAX;
    for(auto &[k,v]:m){
        if(mn == INT_MAX )mn = min(mn,v);
        else mn = hcf(mn,v);
        //cout << k << ' ' << v << endl;
    }
    if(mn == INT_MAX ){
        for(ll i=1;i<=n ;i++) cout << i << ' ';
        cout << endl;
        return;
    }
    vector<ll> nums;
    for(ll i =1;i<=mn ; i++){
        if(mn%i == 0) nums.push_back(i);
    }
    for(auto e:nums) cout << e << ' ';
    cout << endl;
}



int main(){
    int t;
    cin >>t;
    while(t--) solve();
}