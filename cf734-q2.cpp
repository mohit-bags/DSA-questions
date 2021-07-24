#include <bits/stdc++.h>
#define int long long int
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
signed main(){
    int t;cin >> t;
    while(t--){
        string s;cin >> s;
        int n=s.length();
        map<char,int> mp;
        int c=0;
        int i=0;
        while(i<n){
            mp[s[i]]++;
            i++;
        }
        int r=0,g=0;
        for(auto i:mp){
           int k=i.second;
           if(k>=2){
               r++;g++;
           }
           else if(k==1){
               if(r<=g)r++;
               else g++;
           }
        }
        if(r!=g)r--;
        cout << r << endl;
    }
}