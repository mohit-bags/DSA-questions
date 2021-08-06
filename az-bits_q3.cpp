#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define N 1000001

signed main(){
    IOS;
    int t;cin>>t;
    int powerOfTwo[N];
    powerOfTwo[0] = 1LL;
    for(int i=1;i<N;i++){
        powerOfTwo[i] = (powerOfTwo[i-1],powerOfTwo[i-1]);
    }
    while(t--){
        
        int n; cin >> n;
        int arr[n]; 
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int c[31]={0};
        for(int i=0;i<31;i++){
             for(int j=0;j<n;j++)
             {
                 if(arr[j]&(1LL<<i))
                    c[i]++;
             }
        }
        int poww=0;
        while(true){
            int ans=0;
        for(int i=0;i<31;i++){
            if(c[i])
            {
                ans+=(1<<i);
                c[i]--;
            }
        }
        poww+=ans*ans;
        if(ans==0)break;
     }
    cout << poww << endl;
    }
}


