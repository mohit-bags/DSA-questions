#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

signed main(){
    IOS;
    int t;cin>>t;
    while(t--){
        int n; cin >> n;
        string s;cin >> s;
        vector<int> ind[26];
        for(int i=0;i<26;i++)ind[i].push_back(-1);
        for(int i=0;i<n;i++)
            ind[s[i]-'a'].push_back(i);
        for(int i=0;i<26;i++)
            ind[i].push_back(n);
        int ans=0;
        for(int i=0;i<26;i++){
            for(int j=1;j<(int)ind[i].size()-1;j++){
                ans+=(ind[i][j]-ind[i][j-1])*(ind[i][j+1]-ind[i][j]);
            }
        }
        cout << ans << endl;
    }
}