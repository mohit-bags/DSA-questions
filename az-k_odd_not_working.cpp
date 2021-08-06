#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int dist=0;
void insert(int n)
{
    if(n%2)dist++;
}
void remove(int n){
    if(n%2)dist--;
}
multiset<int> mt;
signed main(){
    int t;
    cin >> t;
    while(t--){
        int n,k,d;
        cin >> n >> k >> d;
        int arr[n];
        int pre[n];
        cout << "2"<<endl;
        for(int i=0;i<n;i++){
            cin >> arr[i];
            pre[i]=arr[i];
            if(i)pre[i]+=pre[i-1];
        }
        cout << "0"<<endl;
        int head=-1,tail=0,ans=-1e18;
        bool impossible=true;
        cout << tail << " " << n<<"____";
        while(tail<n){
            cout << "1";
            while(head+1<n && (dist<k  || (dist==k && arr[head+1]%2==0))){
                cout << "#";
                head++;
                insert(arr[head]);
                int xx = tail?pre[tail-1]:0;
                if(pre[head]<=(d+xx))
                {
                    mt.insert(pre[head]);
                    auto it= upper_bound(mt.begin(),mt.end(),d+xx);
                    if(it!=mt.begin())
                    {
                        it--;
                        ans=max(ans,*it);
                    }
                }
                cout << "..";
            }
            if(tail>head){
                tail++;
                head=tail-1;
            }
            else{
                remove(arr[tail]);
                mt.erase(mt.find(pre[tail]));
                tail++;
            }
            cout << "END";
        }
        if(ans==-1e18)
            cout<<"IMPOSSIBLE"<<endl;
        else
        cout << ans << endl;
    }
}