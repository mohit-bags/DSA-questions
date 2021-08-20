#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main(){
    int n; cin >> n;
    vector<int> A(n);
    for(int i=0;i<n;i++)cin>>A[i];
    int suf[n];
    memset(suf,0,sizeof(suf));
    suf[n-1]=A[n-1];
    for(int i=n-2;i>=0;i--)
        suf[i]=max(suf[i+1],A[i]);
    int ans=-1;
    for(int j=1;j<n-1;j++){
        int r=suf[j+1];
        int lmax=-1;
        for(int i=0;i<j;i++){
            if(A[i]<A[j])
            lmax=max(lmax,A[i]);
        }
        ans=max(ans,A[j]+lmax+r);
        if(ans==18){
            cout << A[j] << " "<< lmax << " " << r<<endl;
        }
    }
    cout << ans << endl;
}


 