// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >>n;
    vector<char> s(n);
    for(int i = 0 ;i<n ;i++){
        cin >> s[i];
    }
    int co = 0;
    vector<int> b;
    for(int i = 0 ; i< n ; i++){
        if(s[i] == '0'){
            co++;
            b.push_back(i+1);
        }
    }
    if(co==n) cout << 0 << endl;
    else{
        cout << co << endl;
        for(auto e:b) cout << e << ' ';
        cout << endl;
    }
    
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