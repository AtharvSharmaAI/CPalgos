// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
typedef long long ll;


ll fact(ll n , vector<ll> &f){
    f[0] = 1;
    f[1] = 1;
    if(n==0 || n==1) return 1;
    if(f[n] != -1) return (f[n])%mod;
    f[n] = (n*fact(n-1,f))%mod;
    return f[n]%mod;
}




void solve(vector<ll> &f){
    string s;
    cin >> s;
    long long c = 1;
    long long ops = 0;
    ll y = 0;
    int idx = -1;
    for(ll i =0;i<s.size();i++){
        if(s[i] == idx){
            y++;
        }else{
            idx = s[i];
            c = (((c%mod)*((y+1)%mod))%mod);
            c = c%mod;
            if(y!=0)ops += (y);
            y = 0;
        }
    }
    if(y!=0) ops += (y);
    c *= ((y+1)%mod);
    c = ((c%mod)*(fact(ops,f)%mod))%mod;
    c = c%mod;
    cout << ops << ' ' << c << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ll> f(200002 , -1);
    f[0] = 1;
    f[1] = 1;
    int t;
    cin >> t ;
    while(t--){
        solve(f);
       
    }
}