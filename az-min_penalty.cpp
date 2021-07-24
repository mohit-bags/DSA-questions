#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int md=1e9+7;
int dist=0;
int freq[1000010];
void insert(int x){
    freq[x]++;
    if(freq[x]==1)
        dist++;
}
void remove(int x){
    freq[x]--;
    if(freq[x]==0)
        dist--;
}
signed main(){
    IOS;
    int t;
    cin >> t;
    while(t--){
        memset(freq,0,sizeof(freq));
        dist=0;
        int n,d; cin >> n >> d;
        int arr[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
            if(i<d)insert(arr[i]);
        }
        int head=d-1,tail=0,ans=dist;
       while(head<n){
           ans=min(ans,dist);
           head++;
           if(head==n)break;
           insert(arr[head]);
           remove(arr[tail]);
           tail++;
       }
        cout << ans << endl;
    }
}