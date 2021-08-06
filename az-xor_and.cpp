#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define N 1000001
int addmod(int a,int b){
   a = a+b;
   if(a>=mod)
       a-=mod;
   return a;
}

signed main(){
    IOS;
    int t;cin>>t;
    int powerOfTwo[N];
    powerOfTwo[0] = 1LL;
    for(int i=1;i<N;i++){
        powerOfTwo[i] = addmod(powerOfTwo[i-1],powerOfTwo[i-1]);
    }
    while(t--){
        
        int n; cin >> n;
        int arr[n]; 
        for(int i=0;i<n;i++)
            cin>>arr[i];
      
        int xorpair=0,andpair=0,xorsub=0,andsub=0;
        for(int i=0;i<31;i++){
            int c1=0,c0=0;
            for(int j=0;j<n;j++){
                if(arr[j]&(1LL<<i))
                    c1++;
                else
                    c0++;
            }
            xorpair=addmod( xorpair,(1LL<<i)*c0%mod*c1%mod);
            andpair=addmod( andpair,((1LL<<i)*((c1*(c1-1))/2) %mod ));
            if(c1>0)
            xorsub=addmod( xorsub, (1LL<<i)*powerOfTwo[n-1]%mod );
            andsub=addmod( andsub, (1LL<<i)*(powerOfTwo[c1]-1+mod)%mod);
        }
        cout << xorpair << " "<<xorsub << " "<<andpair << " "<<andsub <<endl;
    }
}