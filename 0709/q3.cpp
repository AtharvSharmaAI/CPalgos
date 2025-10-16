#include <bits/stdc++.h>
using namespace std;



int main() {
    // Write C++ code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long a,b;
        cin >> a >> b;
        long long maxi = INT_MIN;
        if( (a*b)%2 == 0 && (a*b)%4 != 0 ) cout << -1 << endl;
        
        else if( a*b % 2 != 0) cout << a*b +1 << endl;
        else{
            if(b%2 == 0) cout << a*b/2 + 2 << endl;
            else cout << -1 << endl;
        }
    
    }

    return 0;
}