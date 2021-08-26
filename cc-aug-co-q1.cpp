#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

signed main(){
    boost;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> vec(n);
        map<int,int> mp;
        int mx=0;
        for(int i=0;i<n;i++)
        {
            cin >> vec[i];
            mp[vec[i]]++;
            mx=max(mx,mp[vec[i]]);
        }
        if(n==1 || n==2)
        {
            cout << "0" << endl;
        }
        else {
            if(mx>1)
            cout << n-mx << endl;
            else 
                cout << n-mx-1 << endl;
        }
    }
}// 2 2 2 6 7