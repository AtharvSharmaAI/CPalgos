#include <bits/stdc++.h>
using namespace std;
int main() {
    // Write C++ code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n ;
        cin >> n ;
        unordered_map<int,int> m;
        unordered_map<int,deque<int>> u;
        vector<int> b(n);
        int y = 1;
        for(int i = 0 ; i< n ; i++){
            cin >> b[i];
            m[b[i]]++;
        }
        bool flag = true;
        for(int c:b){
            if(m[c] % c != 0){
                flag = false;
                break;
            }else if(u[c].empty()){
                int e = m[c]/c;
                deque<int> q(e);
                for(int i = 0 ; i<e ; i++) q[i] = y++;
                u[c] = q;
            }
        }
        if(flag){
            for(int c:b){
                m[c]--;
                cout << u[c].front() << ' ';
                if(m[c] % c == 0) u[c].pop_front();
            }
        }else cout << -1;
        cout << endl;
    }

    return 0;
}