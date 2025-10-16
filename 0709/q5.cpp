#include <bits/stdc++.h>
using namespace std;
int main() {
    // Write C++ code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n),b(n);
        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
        }
        for(int i = 0 ; i < n ; i++){
            cin >> b[i];
        }
        vector<int> z(n);
        z[0] = a[0];
        for(int i = 1 ; i< n ; i++){
            z[i] = max(z[i-1],max(a[i] , b[i]));
        }
        int count = 0;
        for(int i = 0 ; i< n ; i++){
            if(z[i] = b[i]) count++;
        }
        cout << count << endl;
    }

    return 0;
}