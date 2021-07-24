#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int freq[100010]={0};
int countdist;
void insert(int x){
    freq[x]++;
    if(freq[x]==1)
        countdist++;
}
void remove(int x){
    freq[x]--;
    if(freq[x]==0)
        countdist--;
}
signed main(){
    IOS;
    int t; cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
            insert(arr[i]);
        }
        int req=countdist;
        for(int i=0;i<n;i++){
            remove(arr[i]);
        }
        // cout <<"DISTINCT "<< req << endl;
        int head=-1,tail=0,ans=n;
        while(tail<n && head+1<n){
            if(countdist==req){
                ans=min(ans,head-tail+1);
                remove(arr[tail]);
                tail++;
            }
            else{
                head++;
                insert(arr[head]);
            }
        }
         while(tail<n){
             if(countdist==req){
                ans=min(ans,head-tail+1);}
            remove(arr[tail]);
            tail++;
         }
        cout << ans << endl;
        // cout <<"0:" <<countdist << endl;

    }
}