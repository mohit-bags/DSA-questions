#include <bits/stdc++.h>
#define int long long int
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int dp[11][6][6];
int solve(string &s,int i,int sc1,int sc2){
    if(i==10)
        return 10;
    int left=10-i;
    if(i%2==0){
         if(((left/2)+sc1)<sc2 || (sc2+(left/2))<sc1 )
        return i;
    }
    else{
         if(((left/2)+sc1)<sc2 || (1+sc2+(left/2))<sc1 )
        return i;
    }
   
    if(i%2==0){
        int k1,k2,k3;
        k1=k2=k3=LLONG_MAX;
        if(s[i]=='0')
            k1= solve(s,i+1,sc1,sc2);
        else if(s[i]=='1')
            k2= solve(s,i+1,sc1+1,sc2);
        else
            k3= min(solve(s,i+1,sc1+1,sc2),solve(s,i+1,sc1,sc2));
        return min(k1,min(k2,k3));
    }
    else{
         int k1,k2,k3;
         k1=k2=k3=LLONG_MAX;
         if(s[i]=='0')
            k1= solve(s,i+1,sc1,sc2);
        else if(s[i]=='1')
            k2= solve(s,i+1,sc1,sc2+1);
        else
            k3= min(solve(s,i+1,sc1,sc2),solve(s,i+1,sc1,sc2+1));
        return min(k1,min(k2,k3));
    }
}
signed main(){
    IOS;
    int t;cin >> t;
    memset(dp,0,sizeof(dp));
    while(t--){
        string s;
        cin >> s;
        cout << solve(s,0,0,0)<<endl;
    }
}



