#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

signed main(){
    IOS;
    int t;cin>>t;
    while(t--){
        int n,x; cin >> n;
        double sum1=0,sum2=0;
        double s1=1,s2=1;
        vector<double> vec(n);
        double mx=1.0*LLONG_MIN;
        for(int i=0;i<n;i++){
            cin>>vec[i];
            sum1+=vec[i];
            mx=max(mx,vec[i]);
        }
        sum1-=mx;
        double ans= sum1/(n-1) + mx;
        printf("%10f\n",ans);
    }
}

