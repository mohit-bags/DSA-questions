#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

signed main(){
    int t;cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int adj[n+2];
        memset(adj,0,sizeof(adj));
        for(int i=1;i<=n;i++){
            int temp; cin >> temp; // i to n+1 hai, then 0, else 1
            if(temp!=0)
            adj[i]=1;
        }
            if(adj[1]==1){
                cout << n+1 << " ";
                for(int i=1;i<=n;i++) cout << i << " ";
            }
            else if(adj[n]==0)
                for(int i=1;i<=n+1;i++) cout << i << " ";
        
        else
        {
            // V in making
            int i;
            for(i=1;i<n;i++){
                if(adj[i]==0 && adj[i+1]==1)
                    break;
            }
            for(int k=1;k<=n;k++){
                cout << k << " ";
                if(k==i){
                    cout << n+1 << " ";
                }
            }
        }
        cout << endl;
    }
}