// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,x,y;
    cin >> n >> x >> y;
    vector<long long >a(n);
    unordered_map<long long , long long> c;
    c.reserve(n * 2);
    c.max_load_factor(0.25);
    long long count = 0;
    for(int i =0;i<n;i++){
        cin >> a[i];
        long long xx = a[i]%x;
        long long xy = a[i]%y;
        long long key = ((1LL*(x - xx)%x) << 32) | xy;
        count += c[key];
        long long idx = (1LL*(xx)) << 32 | xy;
        c[idx]++;
    }
    cout << count << endl;
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