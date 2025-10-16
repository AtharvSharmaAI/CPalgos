// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main() {
    // Write C++ code here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >>n ;
        string s,v,d;
        cin >> s;
        int x;
        cin >> x;
        cin >> v >> d;
        deque<char> se(s.begin() , s.end());
        for(int i = 0 ; i<x ; i++){
            if(d[i] == 'V')se.push_front(v[i]);
            else se.push_back(v[i]);
        }
        for(char c:se) cout << c ;
        cout << endl;
    }

    return 0;
}