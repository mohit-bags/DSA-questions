#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int md=1e9+7;
int distinct=0;
int freq[100100];
void insert(int x){
    freq[x]++;
    if(freq[x]==1)
        distinct++;
    return ;
}
void remove(int x){
    freq[x]--;
    if(freq[x]==0)
        distinct--;
    return ;
}
void solve(){
    int n,k; cin >> n >> k;

    int arr[n];
    
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int head=-1,tail=0,ans=0;
    while(tail<n){
        while(head+1<n && ((distinct<k) || (distinct==k && freq[arr[head+1]]!=0 ))){
            head++;
            insert(arr[head]);
        }
        ans+=(head-tail+1);
        if(head<tail){
            tail++;
            head=tail-1;
        }
        else{
            remove(arr[tail]);
            tail++;
        }
    }
    cout << ans<<endl;
    return ;
}

signed main(){
    IOS;
    memset(freq,0,sizeof(freq));
    int t;cin >> t;
    while(t--){
        
        solve();
    }
    return 0;
}