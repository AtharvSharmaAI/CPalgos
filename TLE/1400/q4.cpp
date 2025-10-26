#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

void solve(){
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll i =0 ;i<n ; i++) cin >> a[i];
    if(k > 2){
        cout << 0 << endl;
        return;
    }else if(k==1){
        sort(a.begin(),a.end());
        ll mn = LLONG_MAX;
        for(int i=1 ;i<n;i++) mn = min(abs(a[i-1]-a[i]),min(mn,a[i]));
        mn = min(mn,a[0]);
        cout << mn << endl;
        return;
    }else{
        vector<ll> x;
        ll mn = LLONG_MAX;
        sort(a.begin(),a.end());
        for(int i = 0 ; i<n;i++){
            mn = min(mn,a[i]);
            for(int j = i+1 ; j<n ;j++){
                ll g = abs(a[j]-a[i]);
                ll p = (lower_bound(a.begin(),a.end(),g) - a.begin());
                if(p<n) mn = min(mn,a[p]-g);
                if(p>0) mn = min(mn,g-a[p-1]);
                mn = min(mn,g);
            }
        }
        
        cout << mn << endl;
        return ;
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
}