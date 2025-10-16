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
        //vector<int> s(n);
        string s;
        cin >> s;
        int z = 0;
        int y = 0;
        int sum = 0;
        for(int i = 0 ; i< n ; i++){
            
            if(s[i] == 0){
                if(i != z) sum++;
                z++;
            }
        }
        int ans = (sum%2 == 0)? (sum/2): (sum/2 +1);
        cout << ans << endl;
    }

    return 0;
}