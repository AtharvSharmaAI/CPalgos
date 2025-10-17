#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> sieve(int n){
    vector<bool> is_prime(n+1,true);
    vector<int> p;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
    if(is_prime[i]) p.push_back(i);
    if (is_prime[i] && (long long)i * i <= n) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}
    return p;
}

vector<int> p = sieve(1e6);


void prime_count(unordered_map<ll,ll> &m , int n, vector<int> &p){
    int i = 0;
    while(n > 1){
        if(n%p[i] == 0){
            n = n/p[i];
            m[p[i]]++;
        }else i++;
    }
    return ;
}


void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = -1;
    for(int i=0;i<n ;i++){
        cin >> a[i];
        mx = max(mx,a[i]);
    }
    unordered_map<ll,ll> m;
    for(int i = 0 ;i<n ;i++){
        prime_count(m,a[i],p);
    }
    for(auto &[r,h]:m){
        if(h%n != 0){
            cout << "NO" << endl;
            return ;
        }
    }
    cout << "YES" << endl;
    return ;
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