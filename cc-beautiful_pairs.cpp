#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define N 1000001


signed main(){
    IOS;
    int t;cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        map<int,int> freq;
        for(int i=0;i<n;i++){
            cin >> arr[i];
            freq[arr[i]]++;
        }
        int ans=0;
        for(auto i:freq){
            ans+=i.second*(n-i.second);
        }
        cout<< ans << endl;
    }
}