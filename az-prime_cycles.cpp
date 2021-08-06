#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n;
bool flag[20]={false};
int ans=0;

bool isprime(int num){
    if(num==2 || num==3 || num ==5 || num==7 || num ==11)
        return true;
    if(num==13 || num==17 || num ==19 || num==23 || num ==29 || num==31 || num==37)
        return true;
    
return false;
}
void solve(int prev,int c,int par){
    if(c==n){
        if(isprime(prev+1))
        ans++;
        return;
    }
    for(int i=1+par;i<=n;i++){
        if(!flag[i] && isprime(i+prev)){
            flag[i]=true;
            solve(i,c+1,1-par);
            flag[i]=false;
        }
    }
    return;
}
signed main(){
    IOS;

    cin >> n;
     if(n % 2 == 1) {
        cout << "0\n";
        return 0;
    }
    flag[1]=true;
    solve(1,1,1);   
    cout << ans << "\n";
    // cout << all.size() << endl;
}