#include <bits/stdc++.h>
using namespace std;
int main() {
    // Write C++ code here
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n ;
        
        int a = 1;
        int c = 0;
        vector<long long> ans;
        long long w = n;
        vector<long long> pw(18,10);
        for(int i = 0 ; i< 17 ; i++) pw[i+1] = pw[i]*10;
        //for(long long g : pw) cout << g << ' ';
        while(a <= 18 && n/(long long)(pw[a-1]+1) > 0 ){
            if(n % (long long)(pw[a-1]+1) == 0){
                c++;
                long long x = n/(long long)(pw[a-1]+1);
                ans.push_back(x);
            }
            a++;
        }
        if(c==0) cout << 0 << endl;
        else{
            cout << c << endl;
            for(int i = 0 ; i< c ; i++) cout << ans[c-i-1] << ' ';
            cout << endl;
        }
    }

    return 0;
}