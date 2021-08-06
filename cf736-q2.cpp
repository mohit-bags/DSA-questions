#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

signed main(){
    IOS;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string enemy,us; cin >> enemy >> us;
        us+='0'+us+'0';
        enemy+='0'+enemy+'0';
        int ans=0;
        for(int i=0;i<=n;i++){
            if(us[i]=='1')
            {
                if(enemy[i]=='0')
                {
                    ans++;
                }
                else if(enemy[i-1]=='1'){
                    ans++;
                    enemy[i-1]='Z';
                }
                else if(enemy[i+1]=='1')
                {
                    ans++;
                    enemy[i+1]='Z';
                }

            }
        }
        cout << ans << endl;
    }
}