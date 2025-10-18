#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n),b(n),d;
    for(int i = 0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    vector<int> c(n,0);
    ll mx = INT_MIN;
    for(int i = 0 ; i<n;i++){
        a[i] = a[i]-b[i];
        mx = max(mx,a[i]);
    }
    
    for(int i = 0 ;i<n ; i++){
        if(a[i] == mx) d.push_back(i+1);
    }
    cout << d.size() << endl;
    for(auto e:d) cout << e << ' ';
    cout << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}