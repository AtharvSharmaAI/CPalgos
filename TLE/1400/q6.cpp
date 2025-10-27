#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;


void binary(vector<vector<int>> &m , vector<int> a){
    int j = 1;
    for(auto e:a){
        for(int i = 0 ; i<32;i++){
            if((e >> i)&1){
                if(j==1) m[j][i]++;
                else m[j][i] = m[j-1][i]+1;
            }else if(j!=1)m[j][i] = m[j-1][i];
        }
        j++;
    }
}

vector<int> leadbit(int x){
    vector<int> a(32,0);
    int i =0;
    while(x>0){
        if(x%2==1) a[i] = 1;
        x /=2;
        i++;
    }
    return a;
}


void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n;i++) cin >> a[i];
    vector<vector<int>> m(n+1,vector<int>(32,0));
    int q;
    cin >> q;
    vector<pair<int,int>> b(q);
    binary(m,a);
    for(int i =0;i<q ;i++){
        cin >> b[i].first >> b[i].second ;
    }
    // for(auto r:m){
    //     for(auto e:r) cout << e << ' ';
    //     cout << endl;
    // }
    for(int i =0 ;i<q;i++){
        
        if(b[i].second > a[b[i].first-1]) cout << -1 << ' ';
        else{
        //vector<int> qx= leadbit(b[i].second);
        int l = b[i].first;
        int lo = l;
        int r = n;
        int idx = l;
        while(l<=r){
            int mi = (r+l)/2;
            int num = 0;
            for(int j = 0 ; j<30 ; j++){
                int dif = m[mi][j]-m[lo-1][j];
                if(dif == mi-lo+1){
                    num += (1<<(j));
                    //cout << "nums = " << num << ' ';
                }
            }
            if(num >=b[i].second){
                l = mi+1;
                idx = max(idx,mi);
                //cout <<"idx = "<< idx << ' ';
            }
            else r = mi-1;
        }
        cout << idx << ' ';
        
        }
    }
    cout << endl;
        
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
}