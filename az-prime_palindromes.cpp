#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int a,b,ans;
bool isprime(int num){
    for(int i=2;i*i<=num;i++)
        if(num%i==0)
            return false;
    return true;
}

void generate(int dig,int c,int num){
    if(c==(dig+1)/2){
        int k;
        if(dig%2)k=num/10;
        else  k=num;
        while(k>0){
            num*=10;
            num+=k%10;
            k/=10;
        }
        if(isprime(num) && num>=a && num<=b)
        {           
            // cout << num << endl;
            ans++;
        }
        return;
    }

    for(int i=0;i<10;i++){
        num*=10; num+=i;
        generate(dig,c+1,num);
        num/=10;
    }

}
signed main(){
    IOS;
    cin >> a >> b;
    int c=0;
    int copy=b;
    
    while(copy>0){
        c++;
        copy/=10;
    }
    for(int j=1;j<=c;j++)
    for(int i=1;i<10;i++)
    {
        generate(j,1LL,i);
    }
    cout << ans << endl;

}