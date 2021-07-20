#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

signed main()
{
    IOS;
    int l,r;
    cin >> l >> r;
    vector<bool> vec(r+1,true);
    vec[1]=false;
    vec[0]=false;
    for(int i=2;i*i<=r;i++){
        if(vec[i])
        for(int j=2*i;j<=r;j+=i)
        {
            vec[j]=false;
        }
    }
    vector<int> ans;
    for(int i=l;i<=r;i++)
        if(vec[i])
            ans.push_back(i);
    cout << ans.size() << endl;
    for(int i=0;i<ans.size();i++)
        cout << ans[i] <<  " ";
} 