#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void binsxp(vector<ll> &c){
    c[0] = 1;
    for(int i = 1 ; i<=32 ;i++){
        c[i] = 2*c[i-1];
    }
}


void makebin(int a , unordered_map<int,int> &m){
    vector<int> c(32,0);
    int i = 0;
    while(a>0){
        if(a%2==1){
            c[i] = 1;
            m[i]++;
        }
        i++;
        a = a/2;
    }
}

void solve(vector<ll> &c){
    int n,k;
    cin >> n >> k;
    vector<int> a(n),b;
    unordered_map<int,int> m;
    for(int i =0;i<n;i++) cin >> a[i];
    for(int i =0;i<n;i++) makebin(a[i], m);
    for(int i = 0 ; i<31 ; i++){
        //cout << r <<' '<< h << endl;
        if((n-m[i]) <= k) b.push_back(i);
    }
    sort(b.begin(),b.end(), greater<int>());
    ll maxsum = 0;
    for(auto e:b){
        if(k >=n- m[e]){
            k -=n- m[e];
            maxsum += c[e];
        }
    }
    
    cout << maxsum << endl;
    
}


int main(){
    int t;
    cin >> t;
    vector<ll> c(33,1);
    binsxp(c);
    while(t--) solve(c);
}