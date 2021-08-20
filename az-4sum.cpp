#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

signed main(){
    IOS;
        int n,tar; cin >> n>>tar;
        vector<int> vec(n);
        for(int i=0;i<n;i++){
           cin >> vec[i];
        }
        bool flag=false;
        map<int,int> mp;
        for(int pos=n-2;pos>0;pos--)
        {
            for(int i=0;i<pos;i++)
            { // looping over a a+b==c+d, loop over d, ci pos +1 always
                int count = vec[i]+vec[pos];
                if(mp.find(tar-count)!=mp.end())
                {
                    flag=true;
                    break;
                }
            }
                for(int j=pos+1;j<n;j++)
                {
                    mp[vec[j]+vec[pos]]++;
                }
        }
        if(flag)
            cout << "YES"<<endl;
        else
            cout << "NO" << endl;

}
