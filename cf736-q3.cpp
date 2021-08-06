 #include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

signed main(){
    IOS;
    int t; t=1;
    while(t--){
        int n; cin >> n;
        int m; cin >> m;
        vector<int> adj[n+1];
        for(int i=0;i<m;i++){
            int a,b;cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int q; cin >> q;
        while(q--){
            int opt; cin >> opt;
            if(opt==3){
                int c=n;
                for(int i=1;i<=n;i++){
                    bool rem=false;
                    for(auto j :adj[i]){
                       if(j>i)
                        {
                            c--;break;
                        }
                    }
                }
                 cout << c << endl;
            }
            else{
                int a,b; cin >> a >> b;
                if(opt==1)
                {
                    adj[a].push_back(b);
                    adj[b].push_back(a);
                }
                else {
                    remove(adj[a].begin(),adj[a].end(),b);
                    remove(adj[b].begin(),adj[b].end(),a);


                }
            }
        }
    }
}
