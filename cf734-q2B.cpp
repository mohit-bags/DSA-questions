#include <bits/stdc++.h>
#define int long long int
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int freq[200010]={0};
int K;
bool insert(int x){
    freq[x]++;
    return freq[x]<=K;
}
void remove(int x){
    freq[x]--;
}
signed main(){
    int t;cin >> t;
    while(t--){
        int n; cin >> n>>K;
        vector< pair<int,int>> vec;
        for(int i=0;i<n;i++)
        {
            int k; cin >> k;
            vec.push_back(make_pair(k,i));
        }
        sort(vec.begin(),vec.end());
        int ans[n];
        int col=0;
        
        for(int i=0;i<n;i++){
            if(insert(vec[i].first))
            {
                ans[i]=col;
                col++;
                col%=K;
            }
            else 
                ans[i]=-1;
        }
        int j=n-1;
        while(col>0 && j>=0){
            if(ans[j]!=-1)
            {
            col--;
            ans[j]=-1;
            }
            j--;
        }
        vector< pair<int,int>> res;
        for(int i=0;i<n;i++){
            remove(vec[i].first);
            res.push_back(make_pair(vec[i].second,ans[i]+1));
        }
        sort(res.begin(),res.end());
        for(int i=0;i<n;i++){
            cout << res[i].second << " ";
        }
        cout << endl;
    }
}
