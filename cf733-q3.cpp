#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

bool F(int ind,vector<int> &pre1,int sum2,vector<int> &pre2){
    int n=pre1.size();
    n--;
    int cuts = ind/4;
    int sum1= pre1[n]-pre1[cuts];
    sum1+=(100*(ind-n));
    sum2=pre2[n]-pre2[max(0LL,(ind)/4-(ind-n))];
    
    if(sum1>=sum2)
        return true;
    return false;
}

signed main()
{
    IOS;
    int t;cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> my(n);
        vector<int> ilya(n);

        for(int i=0;i<n;i++)
            cin >> my[i];
        for(int i=0;i<n;i++)
            cin >> ilya[i];

        sort(my.begin(),my.end());
        sort(ilya.begin(),ilya.end());
        vector<int> pre1(n+1,0);
        vector<int> pre2(n+1,0);
        for(int i=1;i<=n;i++){
            pre1[i]+=pre1[i-1]+my[i-1];
            pre2[i]+=pre2[i-1]+ilya[i-1];
        }
        int cuts = n/4;
        int sum1= pre1[n]-pre1[cuts];
        int sum2 = pre2[n]-pre2[cuts];

        if(sum1>=sum2){
            cout << "0" <<endl;
            continue;
        }
        sum2=pre2[n];
        int l=n,r=2*n;
        int ans=r;
        
        while(l<=r){
            int mid= l+(r-l)/2;
            if(F(mid,pre1,sum2,pre2)){
                r=mid-1,ans=mid;
            }
            else
                l=mid+1;
        }
        
        cout << ans-n<<endl;
    }
} 