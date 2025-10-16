#include<bits/stdc++.h>
using namespace std;

bool mexa(int a , int b , int c){
    int maxi = 0;
    int mini = 0;
    int mex = 0;
    maxi = max(a,max(b,c));
    mini = min(a,min(b,c));
    if(mini>0) mex = 0;
    else if(mini >1 ) mex = 1;
    else if(mini >2 ) mex = 2;
    else mex = 3;
    
    return mex == maxi-mini;
}



int main(){
    int t;
    cin >> t ;
    while(t--){
        int n ;
        bool d = true;
        cin >> n ;
        vector<int> a(n); 
        for(int i = 0 ; i<n ; i++) cin >> a[i]; 
        for(int r = 2 ; r<n ; r++){
            int mini = 0;
            int maxi = 0;
            int mex = 0;
            if(a[r-2]!=-1 && a[r-1]!= -1 && a[r] != -1){
                if(!mexa(a[r-2],a[r-2],a[r])) d = false;
            }
            else{
                int count = 0;
                for(int i = r-2 ; i<=r ; i++) if(a[i] == -1) count++;
                if(count == 2){
                    for(int i = r-2 ; i<=r ; i++){
                        if(a[i]==0) d=false;
                    }
                }
                else{
                    for(int i = r-2 ; i<=r ; i++){
                    if(a[i] != -1) continue;
                    else{
                        bool flag = false;
                        for(int j = 0 ; j<=3 ; j++){
                            a[i] = j;

                            bool mexr = mexa(a[r-2],a[r-1],a[r]);
                            if(mexr){
                                flag = true;
                                break;
                            } 
                        }
                        if(!flag){
                            d = false;
                            break;
                        }
                    }
                }
                }
                
            }
        }
        if(d)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}