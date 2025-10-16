// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;



int main() {
    // Write C++ code here
    int t;
    cin >> t ;
    while(t--){
        int x,k;
        cin >> x >> k;
        int c = 0;
        vector<long long> pw(20,1);
        long long cost = 0;
        for(int i = 0 ; i<19 ; i++)pw[i+1] = pw[i]*3;
        for(int i = 18 ; i>= 0 ; i--){
            if(x / pw[i] ==0) continue;
            else{
                int j = x/pw[i];
                x -= j*pw[i];
                cost += j*(pw[i+1] + i*pw[i-1]);
                c += j;
            }
        }
        
        if(c <= k)cout << cost << endl;
        else cout << -1 << endl;
        
    }

    return 0;
}