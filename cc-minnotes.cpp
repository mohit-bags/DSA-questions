#include<bits/stdc++.h>
#define ll long long int
using namespace std;
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> vec(n);
        ll pre[n+1],suf[n+1];
        memset(pre,0,sizeof(pre));
        memset(suf,0,sizeof(suf));
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            cin >> vec[i];
            sum+=vec[i];
        }
        for(int i=1;i<=n;i++){  // pre array from 0 to n , pre[0]=0
            pre[i]=__gcd(pre[i-1],vec[i-1]);
        }
        for(int i=n-1;i>=0;i--){ // suff array from 0 to n , suff[n]=0
            suf[i]=__gcd(suf[i+1],vec[i]);
        }
        ll ans=min(LLONG_MAX,sum/pre[n]);
        for(int i=0;i<n;i++){
            ll temp = sum-vec[i];
            ll gcdd = __gcd(pre[i],suf[i+1]);
            ans = min(ans,(temp/gcdd) + 1);
        }
        cout << ans << endl;
    }
}