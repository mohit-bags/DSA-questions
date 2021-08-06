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
        int arr[n];
        for(int i=0;i<n;i++)
            cin >> arr[i];
        int num=0;
        for(int i=31;i>=0;i--){
            int c=0;//count of ones
            for(int j=0;j<n;j++){
                if( arr[j]& (1<<i) )
                    c++;
            }
            if(c>=n-c)
                num+= 1<<i;
        }
        int ans=0;
        for(int j=0;j<n;j++){
            ans=ans|arr[j]^num;
        }
            
        cout << num<<" "<<ans<<endl;
    }
}