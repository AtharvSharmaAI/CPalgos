#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;

        vector<long long> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

        sort(a.begin(), a.end(), greater<long long>());
        sort(b.begin(), b.end(), greater<long long>());

        vector<long long> c(n+1, 0), d(m+1, 0);
        for (int i = 1; i <= n; i++) c[i] = c[i-1] + a[i-1];
        for (int i = 1; i <= m; i++) d[i] = d[i-1] + b[i-1];

        while (q--) {
            int x, y, z;
            cin >> x >> y >> z;

            long long sum = 0;
            int lo = max(0,z - y);
            int hi = min(x,z);

            for (int j = lo; j <= hi; j++) {
                int re = z - j;
                if (re <= y) {
                    sum = max(sum, c[j] + d[re]);
                }
            }

            cout << sum << "\n";
        }
    }
    return 0;
}
