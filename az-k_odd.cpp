#include <bits/stdc++.h>
#define int long long int
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int dist=0;
int sum=0;
void insert(int n)
{
    sum+=n;
    if(n%2)dist++;
}
void remove(int n){
    sum-=n;
    if(n%2)dist--;
}
signed main(){
    IOS;
    int t;
    cin >> t;
    while(t--){
        int n,k,d;
        cin >> n >> k >> d;
        int arr[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        int head=-1,tail=0,ans=0;
        bool impossible=true;
        while(tail<n){
            while(head+1<n &&  sum+arr[head+1]<=d && (dist<k  || (dist==k && arr[head+1]%2==0))){
                head++;
                insert(arr[head]);
                impossible=false;
            }
            ans+=sum;
            if(tail>head){
                tail++;
                head=tail-1;
            }
            else{
                remove(arr[tail]);
                tail++;
            }
        }
        cout << ans << endl;

    }
}