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
        int mx1=-1;
        int freq=0;
        for(int i=0;i<n;i++){
            cin >> arr[i];
            if(i)mx1=max(mx1,arr[i]*arr[i-1]);
        }
        cout << mx1 << endl;
    }
}