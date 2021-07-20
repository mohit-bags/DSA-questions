#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int md= 1e9+7;

int mul(int a,int b){
    return (a*b)%md;
}
int power(int a,int b){ // a pow b
    int res=1;
    while(b>0){
        if(b%2==1){
            res=mul(res,a);
        }
        a=mul(a,a);
        b>>=1;
    }
    return res%md;
}
signed main(){
    IOS;
    int n,m;
    cin >> n >> m;
    int ans=0;
    for(int i=1,la;i<=n;i=la+1){
        la=n/(n/i);
        int x=n/la;x%=md;
        if(x<0)
            x+=md;
        int y = 1LL * (la - i + 1) % md;
        if(y < 0) y += md;

        int temp = (mul(y,power(x,m)))%md;
        if(temp<0)
            temp+=md;
        ans= (ans + temp%md)%md;
        if(ans<0){
            ans=ans+md;
        }
    }
    cout <<  ans;
    return 0;
}