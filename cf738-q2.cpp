#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int dp[110][2];
string ans_s;
int solve(string s,int i,char prev){

    int kk=prev=='R'?1:0; //R->1, B->0

    int n=s.length();

    if(i==n)
        return 0;

    if(dp[i][kk]!=-1)
        return dp[i][kk];
    
    int ans=s[i]==prev?1:0;
    if(s[i]=='?'){
       if(kk)
       {
         ans+=min(1+solve(s,i+1,'R'),solve(s,i+1,'B'));
         if(1+solve(s,i+1,'R')<solve(s,i+1,'B'))
            ans_s=ans_s+'R';
         else ans_s=ans_s+'B';
       }
       else{
            ans+=min(solve(s,i+1,'R'),1+solve(s,i+1,'B'));
            if(solve(s,i+1,'R')<1+solve(s,i+1,'B'))
                ans_s=ans_s+'R';
            else ans_s=ans_s+'B';
       }
    }
    else 
    {
        ans+=solve(s,i+1,s[i]);
        ans_s+=s[i];
    }

    return dp[i][kk]=ans;
}
signed main(){
    int t;cin >> t;
    while(t--)
    {
        ans_s="";
        memset(dp,-1,sizeof(dp));
        int n; cin >> n;
        string s; cin >> s;
        if(s[0]=='?')
        {
            int k1=solve(s,1,'R');
            memset(dp,-1,sizeof(dp));
            int k2=solve(s,1,'B');
            if(k1<k2)
                ans_s+='R';
            else 
            {
                ans_s="";
                memset(dp,-1,sizeof(dp));
                solve(s,1,'B');
                ans_s+='B';
            }
        }
        else{
            solve(s,1,s[0]);
            ans_s+=s[0];
        }
        for(int i=n-1;i>=0;i--){
            cout<<ans_s[i];
        }
        cout << endl;
    }
}
