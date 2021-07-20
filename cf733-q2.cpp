#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

signed main()
{
    IOS;
    int t;cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        // 3>=, 3>=
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!(i&1) || i==n-1){
                    if(i==0 || (i==n-1 && (i-1)%2==1)){ //first row or last row full
                        if(!(j&1)){
                            cout << "1";
                        }
                        else
                            cout << "0";
                    }
                    else if(i==n-1 && (i-1)%2==0){ //last row print, but prev row had 1s on edges
                         if(!(j&1) && j!=0 && j!=m-1 && j>1 && j<m-2){
                            cout << "1";
                        }
                        else
                            cout << "0";
                    }
                    else{ //mid rows
                         if((j==0 || j==m-1))
                            cout << "1";
                        else 
                            cout << "0";
                    }
                }
                else
                    cout << "0";
            }
            
            cout << endl;
        }
    }
}