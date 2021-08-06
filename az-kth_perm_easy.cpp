#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

signed main(){
    IOS;
    int n,k;
    cin >> n >> k;
    int arr[n];
    for(int i=0;i<n;i++)arr[i]=i+1;
    k--;
    while(k--){
        next_permutation(arr,arr+n);
    }
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
}