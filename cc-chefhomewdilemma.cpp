#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int

signed main(){
    IOS;
    int t;cin >> t;
    while(t--){
        int N,k;
        cin >> N >> k;
        int dp[N];
        int arr[N];
        deque<int> dq;
        dq.clear();
        for(int i=0;i<N;i++)
            cin >> arr[i];
        if(N<=k)
        {
            cout << "0" << endl;
            continue;
        }
        int i=0;
        for( i=0;i<=k;i++){
            dp[i]=arr[i];
            //insert
            while(!dq.empty() && arr[dq.back()]>=arr[i])
                dq.pop_back();
            dq.push_back(i);
        }

        for(i=k+1;i<N;i++){
            if(!dq.empty() && dq.front()<i-k-1)
                dq.pop_front();
            dp[i]=arr[i]+dp[dq.front()];
            while(!dq.empty() && dp[dq.back()]>=dp[i])
                dq.pop_back();
            dq.push_back(i);
        }
        int ans=LLONG_MAX;
        reverse(dp,dp+N);
        for(int i=0;i<=k;i++)
        {
            ans=min(ans,dp[i]);
            // cout << dp[i] << " ";
        }
        cout << ans << endl;
    }   
}
