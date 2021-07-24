#include <bits/stdc++.h>
#define int long long int
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
signed main(){
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        if(n%3==0){
            cout << n/3 << " " << n/3 << endl;
            continue;
        }
        else if(n%3==1){
            cout << (n/3 + 1) << " " << n/3 << endl;
        }
        else {
            cout << n/3 <<  " "<< (n/3 + 1)<<endl;
        }
    }
}