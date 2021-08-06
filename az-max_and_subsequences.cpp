#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define N 1000001

signed main(){
    IOS;
    int t;cin>>t;
    while(t--){
        
        int n,x; cin >> n>>x;
        vector<int> vec(n);
        for(int i=0;i<n;i++)
            cin>>vec[i];
        int ans=0;
        for(int i=30;i>=0;i--){
            int cnt=0;
             vector<int> temp;
            for(int j=0;j<(int)vec.size();j++){
                if(vec[j]&(1LL<<i))
                {
                    cnt++;
                    temp.push_back(vec[j]);
                }
            }
            if(cnt>=x){
                vec=temp;
                ans+=(1LL<<i);
            }
        }
        cout << ans << endl;
    }
}