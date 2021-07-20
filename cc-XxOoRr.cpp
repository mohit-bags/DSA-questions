#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
    boost;
    int t; cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int> vec(n);
        for(int i=0;i<n;i++)
            cin>>vec[i];
        vector<ll> bitcount(32,0);
        for(int i=0;i<32;i++){
            for(int j=0;j<n;j++){
                if(vec[j]&(1<<i))
                    bitcount[i]++;
            }
        }
        
        int ans=0;
        for(int i=0;i<32;i++){
            // cout <<  ceil((1.0*bitcount[i])/(1.0*k)) << "-=";
            ans+=ceil((1.0*bitcount[i])/(1.0*k));
        }
        cout << ans<<endl;
    }
}