#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s;cin >> s;
        int res=13*(n+1)*n;
        int j=0;
        while(j<26){
            int prev=0;
            int i;
            int ccc=0;
            for( i=0;i<n;i++)//abca
            {
                if(s[i]==char(j+'a'))
                {   
                    ccc+=((i-prev)*(i-prev+1))/2;
                    prev=i+1;
                }
            }
        ccc+=((i-prev)*(i-prev+1))/2;
        res-=ccc;
        // cout<<char(j+'a')<<endl;
        // cout << ccc << endl;
        j++;
    }
    cout << res<<endl;
}
}
