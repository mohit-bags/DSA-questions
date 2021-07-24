#include <bits/stdc++.h>
#define int long long int
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

signed main(){
    IOS;
    int t; cin >> t;
    while(t--){
        int n,target;
        cin >> n >> target;
        int arr[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        sort(arr,arr+n);
        int mn=LLONG_MAX;
        for(int j=1;j<n-1;j++){
            int i=0,k=n-1;
            while(i<j && k>j){
                int sm=arr[i]+arr[j]+arr[k];
                if(sm==target){
                    mn=0;
                    break;
                }
                else 
                    mn=min(1LL*mn,1LL*abs(target-sm));
                if(sm<target)
                    i++;
                else 
                    k--;

            }
        }
        cout << mn << endl;
    }
}