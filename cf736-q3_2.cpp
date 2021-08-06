#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

signed main(){
    IOS;
    int t; t=1;
    while(t--){
        int n; cin >> n;
        int m; cin >> m;
        int arr[n+2];
        int c=0;
        memset(arr,0,sizeof(arr));
        for(int i=0;i<m;i++){
            int a,b;cin>>a>>b;
            if(a>b)
            {   arr[b]++;
                if(arr[b]==1)c++;
            }
            else{
                 arr[a]++;
                 if(arr[a]==1)c++;
            }
        }
        int q; cin >> q;
        // for(int i=0;i<=n;i++){
        //     cout << i <<"->"<< arr[i] << endl;
        // }
        // cout << c << endl;
        while(q--){
            int opt; cin >> opt;
            if(opt==3){
                 cout << n-c << endl;
            }
            else{
                int a,b; cin >> a >> b;
                if(opt==1)
                {
                     if(a>b)
                     {  arr[b]++;
                        if(arr[b]==1)
                            c++;
                     }
                    else {
                        arr[a]++;
                        if(arr[a]==1)
                            c++;
                    }
                }
                else {  
                   if(a>b)
                   {    arr[b]--;
                        if(arr[b]==0)c--;
                   }
                 else {
                     arr[a]--;
                     if(arr[a]==0)c--;
                 }
                }
            }
        //     for(int i=0;i<=n;i++){
        //     cout << i <<"->"<< arr[i] << endl;
        // }
        // cout << c << endl;
        }
    }
}
