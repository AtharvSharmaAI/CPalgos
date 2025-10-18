#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int c = 0;      
    int ind = 0;    
    int l = 1, r = n;
    bool flag = false;

    cout << "1 " << l << ' ' << r << endl;
    cout.flush();
    long long a;
    cin >> a;

    cout << "2 " << l << ' ' << r << endl;
    cout.flush();
    long long b;
    cin >> b;

    ind = b - a;
    c += 2;


    int ansL = 1;
    int lo = 1, hi = n;

    while (lo <= hi && c + 2 <= 40) {
        int mid = (lo + hi) / 2;

        cout << "1 " << 1 << ' ' << mid << endl;
        cout.flush();
        long long psum;
        cin >> psum;

        cout << "2 " << 1 << ' ' << mid << endl;
        cout.flush();
        long long asum;
        cin >> asum;

        int dif = asum - psum;
        c += 2;

        if (dif == 0) {
            lo = mid + 1;  // interval starts after mid
        } else {
            ansL = mid;    // possible start
            hi = mid - 1;
        }
    }

    int ansR = ansL + ind - 1;

    cout << "! " << ansL << ' ' << ansR << endl;
    cout.flush();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
