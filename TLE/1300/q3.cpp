#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    bool flag = false;
    vector<long long> prsm(n+1);
    map<long long , long long> m;
    m[0]++;
    for(int i=0 ;i<n;i++){
        cin >> a[i];
    }
    for(int i = 0 ;i<n ;i++){
        
        prsm[i+1] = prsm[i] + ((i%2==1)?(-1):(1))*a[i];
        if(m[prsm[i+1]] >0){
            cout << "YES" << '\n';
            return ;
        }
        m[prsm[i+1]]++;
    }
    cout << (("NO")) << endl;  

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t ;
    while(t--){
        solve();
    }
}