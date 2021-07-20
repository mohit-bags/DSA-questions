#include<bits/stdc++.h>
using namespace std;

#define ll long long int

signed main(){
    // sieve code
    int n; cin >> n;
    vector<bool> vec(n+1,true);
    for(int i=2;i<=n;i++){
        if(vec[i]){ 
            for(int j=2*i;j<=n;j+=i){
                vec[j]=false;
            }
        }
    }
    for(int i=2;i<=n;i++)
        if(vec[i])cout << i << " ";

}