#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int t; cin >> t;
    while(t--){
        int n;cin >> n;
        vector<int> a(n+1);
        for(int i=0;i<n;i++)
            cin >> a[i];
        int k=0;
        for(int i=0;i<n;i++){

            for(auto j=-i-2;j<n;j+=a[i])
            {
                if(i<j && a[i]*a[j]==i+j+2)
                    k++;
            }
        }
        cout << k <<endl;
    }
}