#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef  pair<int,int> ii;

signed main(){
    boost;
    int t; cin >> t;
    for(int _=1;_<=t;_++){
        int n,c;
        cin >> n >> c;

        vector<ii> vec;
        int mx=-1;
        for(int i=0;i<n;i++){
            ii temp;
            cin>>temp.first;
            cin>> temp.second;
            vec.push_back(temp);
            mx=max(mx,temp.second);
        }
    int pre[mx+1];
    memset(pre,0,sizeof(pre));
    for (auto it = vec.begin(); it != vec.cend(); ++it) {
        pre[it->first+1]++;
        pre[it->second]--;
    }
    for(int i=1;i<=mx;i++)
        pre[i]+=pre[i-1];
        
    sort(pre,pre+mx+1,greater<int>());

    int ans=n;
    for(int i=0;i<c;i++)
    {   
        if(pre[i]==0)break;
        ans+=pre[i];
        // c--;
    }
    cout << "Case #"<<_<<": "<<ans<<endl;
    }
    return 0;
}