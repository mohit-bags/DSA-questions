#include <bits/stdc++.h>
#define int long long int
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int dist=0;
int freq[1000010]={0};
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
int distinctk(int n,int *arr,int k){
    int tail=0,head=-1;
    int ans=0;
    while(tail<n){
        while(head+1<n && ((dist==k && freq[arr[head+1]]!=0) || dist<k))
        {
            head++;
            insert(arr[head]);
        }
        ans=ans+(head-tail+1);
        if(head<tail){
            tail++;
            head=tail-1;
        }
        else{
            remove(arr[tail]);
            tail++;
        }
    }
        return ans;
}
signed main(){
    int t;cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int arr[n];
        for(int i=0;i<n;i++)
            cin >> arr[i];
        int c1=distinctk(n,arr,k);
        int c2=distinctk(n,arr,k-1);

        cout << c1-c2 << endl;
    }
}
