#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool bins(vector<ll> &b, ll y){
    int l = 0;
    int r = b.size()-1;
    while(l<=r){
        int m = l + (r-l)/2;
        //cout << b[m]<<' '<<y<< endl;
        if(b[m] == y) return true;
        else if(b[m] < y) l = m+1;
        else r = m-1;
    }
    return false;
}


void poc(vector<vector<ll>> &p){
    for(int i = 2 ;i<=1000 ; i++){
        ll u = 1;
        int w=0;
        while(u < 1e6){
            u *= i;
            if(w>1)p[i].push_back(u);
            w++;
        }
    }
}

void solve(vector<vector<ll>> &p){
    ll n;
    cin >> n;
    for(int i = 2 ; i<=1000; i++){
        ll x = (i-1)*n + 1;
        
        if(bins(p[i],x)){
            cout << "YES" << endl;
            return ;
        }
    }
    cout <<"NO" << endl;
    return ;

}


int main(){
    int t;
    cin >> t;
    vector<vector<ll>> p(1001);
    poc(p);
    // for(int i = 2 ;i<=1000;i++){
    //     for(auto r:p[i]) cout << r << ' ';
    //     cout << endl;
    //     cout << bins(p[i],i);
    //     cout << endl;
    // }
    while(t--){
        solve(p);
    }
}