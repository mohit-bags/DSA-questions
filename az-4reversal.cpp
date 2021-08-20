#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
set<string> st;
string rev(string a,int l,int r){
    reverse(a.begin()+l,a.begin()+r+1);
    return a;
}
void solve(string a,int left){
    if(left==0){
        st.insert(a);
        return;
    }
    for(int i=0;i<(int)a.length();i++){
        for(int j=i;j<(int)a.length();j++){
            solve(rev(a,i,j),left-1);
        }
    }
    return;
}
signed main(){
    IOS;
    int t; cin >> t;
    while (t--)
    {
       string s,target;
       cin >> s >> target;
       solve(s,2);
       set<string> a=st;
       st.clear();
       solve(target,2);
       set<string> b=st;
       bool flag=false;
       for(auto i:a){
           if(b.find(i)!=b.end())
            {
                cout << "YES"<<endl;
                flag=true;
                break;
            }
       }
       if(!flag)
            cout << "NO"<<endl;

    }
}    