#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

signed main()
{
    IOS;
    int t;cin >> t;
    while(t--){
        int n; cin >> n;
        int mx=0;
        while(n>0){
            mx=max(n%10,mx);
            n/=10;
        }
        cout << mx << endl;
    }
}