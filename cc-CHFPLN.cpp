#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

signed main(){
    IOS;
    int t;cin >> t;
    while(t--){
        int n;
        cin >> n;
        int freq[200010]={0};
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            freq[arr[i]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(freq[arr[i]],arr[i]-1);
            freq[arr[i]]=0;
        }
        cout << ans<<endl;
    }
}


