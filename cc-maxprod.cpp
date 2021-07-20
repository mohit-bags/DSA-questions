#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
    boost;
    ll t;cin>>t;
    while(t--){
        ll d,x,y,z;
        cin >> d >> x >> y >> z;
        ll k1=7*x;
        ll k2 = y*d + (7-d)*z;
        cout << max(k1,k2)<<endl;
    }
}