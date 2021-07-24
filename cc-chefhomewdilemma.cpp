#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
int N,k;

int arr[1000010];
int solve(int i,int cont,vector<vector<int>> &dp){
    if(cont>k)
        return 1LL*1e9;
    if(i>=N)
        return 1LL*0;
    if(dp[i][cont]!=-1)
        return dp[i][cont];
    int ans,ans1;
    if(cont<k)
        ans= min(arr[i]+solve(i+1,0,dp),solve(i+1,cont+1,dp));
    else
        ans=arr[i]+solve(i+1,0,dp);
    return dp[i][cont]=ans;
    
}
signed main(){
    IOS;
    int t;cin >> t;
    while(t--){
        cin >> N >> k;
        vector<vector<int>> dp(N+2,vector<int>(k+2,-1));
        for(int i=0;i<N;i++)
            cin >> arr[i];

        cout << solve(0LL,0LL,dp)<<endl;
    }   
}