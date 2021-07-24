#include <bits/stdc++.h>
#define int long long int
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool rec(string a,string b,int ib, int ia,bool move_left){
    if(ib==b.length())
        return true;
    bool ff=false;
    bool fff=false;
    
    if(b[ib]==a[ia-1])
        fff= rec(a,b,ib+1,ia-1,true);
    if(move_left==false && b[ib]==a[ia+1])
        ff = rec(a,b,ib+1,ia+1,false);
    return (ff || fff);
}
signed main(){
    IOS;
    int t;cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        a="*"+a+"*";
        int n=b.length();
        int m=a.length();
        bool flag=false;
        char ch = b[0];
        int ti=0;
        for(int j=0;j<m;j++){
            if(a[j]==ch){
                // cout << j;
                bool k=false;
                 flag = rec(a,b,ti+1,j,k);
                if(flag)break;
            }
        }
        if(flag)
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
    
    return 0;
}
