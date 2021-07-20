#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long int
// #include <boost/multiprecision/cpp_int.hpp>
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int a,b;
        cin >> a>>b;
        if((b&(b-1)) == 0)
            printf("Yes\n");
        else 
             printf("No\n");
        
    }
}
