#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
signed main(){
    boost;
    int t; cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<string> vec(n);
        for(int i=0;i<n;i++)
            cin >> vec[i];

        int arr[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                arr[i][j]=vec[i][j]-'0';
        }
        int xorr[n];
        memset(xorr,0,sizeof(xorr));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                xorr[j]=xorr[j]^arr[i][j];
            }
        }
        for(int i=0;i<n;i++)
            cout << xorr[i];
        cout << endl;
    }
}