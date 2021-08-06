#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

signed main(){
    IOS;
    int t;cin >> t;
    while(t--){
        int x,y;cin>>x>>y;
        if(__gcd(x,y)>1){
            cout << "0\n";
        }
        else if(__gcd(x+1,y)>1 || __gcd(x,y+1)>1){
            cout << "1\n";
        }
        else{
            cout << "2\n";
        }
    }
    cout << (1<<2) <<endl;
    cout << (8>>2) << endl;
}