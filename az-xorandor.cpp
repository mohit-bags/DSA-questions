#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

signed main(){
    IOS;
    int t;cin>>t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        int pre[n+10][31];
        memset(pre,0,sizeof(pre));
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int i=0;i<=30;i++)
        {
            for(int j=0;j<n;j++)
                if(arr[j]&(1LL<<i))
                {
                    pre[j][i]=1;
                }
        }
        
        for(int i=0;i<=30;i++)
            for(int j=0;j<n;j++)
                if(j)
                    pre[j][i]+=pre[j-1][i];
        int q;cin>>q;
        while(q--){
            int l,r;
            cin >> l >> r;
            r--;l--;
            int xxor=0,Oor=0,Aand=0;
            for(int i=0;i<=30;i++){
                int cz=0;int co=0;
                int xxx=l?pre[l-1][i]:0;
                co=pre[r][i]-xxx;
                cz=r-l+1-co;
                if(cz>co)
                    xxor+=(1LL<<i);
                if(co>0)
                    Aand+=(1LL<<i);
                if(cz>0)
                    Oor+=(1LL<<i);
            }
        int ans=xxor+Aand+Oor;
        cout << ans <<endl;
    }
    }
}
