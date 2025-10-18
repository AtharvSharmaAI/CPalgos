// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int binp(int a){
    int y = 0;
    while(a > 1){
        a = a/2;
        y++;
    }
    return y;
}

vector<long long> bin(int a){
    vector<long long > c;
    while(a >=1){
        c.push_back(a%2);
        a = a/2;
    }
    reverse(c.begin(),c.end());
    return c;
}

int ms(int num){
    int temp = num;
    int pos = 0;
    while (temp > 1) {
        temp >>= 1;
        pos++;
    }
    int mask = 1 << pos;

    // Clear the leftmost bit
    num = num & (~mask);
    return num;
}

void solve(){
    int a,b;
    cin >> a >> b;
    if(a==b) cout << 0 << endl;
    else if(a > b){
        if(binp(a) == binp(b)){
            cout << 1 << endl;
            cout << (a^b) << endl;
        }else{
            cout << 2 << endl;
            cout << (ms(a)^b) << ' ' << (ms(a)^a)<< endl;
        }
        
    }else{
        if(binp(a) < binp(b)) cout << -1 << endl;
        else{
            int u = a ^ b;
            cout << 1 << endl;
            cout << u << endl;
        }
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