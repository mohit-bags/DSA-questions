#include<bits/stdc++.h>
using namespace std;

signed main(){
    int t; cin >> t;
    while(t--){
        string s,to;
        cin >> s >> to;
        if(s.compare(to)==0)
        {
            cout << "YES" << endl;
            continue;
        }
        if(to.length()>s.length()){
            cout << "NO" << endl;
            continue;
        }
        int ind=to.length()-1;
        bool flag=false;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==to[ind])
            {
                ind--;
                if(ind==-1)
                {
                    flag=true;
                    break;
                }
            }
            else{
                i--;
            }
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout << "NO"<<endl;

    }
}   