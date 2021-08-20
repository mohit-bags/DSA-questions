#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define N 1000001
int m;
vector<int> generate(vector<int> vec)// all pair sums
{
    int n=vec.size();
    vector<int> st;
    for(int i=0;i<(1<<n);i++){
        int sum=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j))
            {
                sum=(sum+vec[j]%m)%m;
            }
        }
        st.push_back(sum);
    }
    return st;
}
signed main(){
    IOS;
    int t;t=1;
    while(t--){
        
        int n; cin >> n>>m;
        vector<int> vec[2];
        for(int i=0;i<n;i++){
            int in; cin >> in;
            vec[i&1].push_back(in%m);
        }
        vector<int> a=generate(vec[0]);
        vector<int> b=generate(vec[1]);
        sort(b.begin(),b.end());
        // for(int i=0;i<(int)a.size();i++)
        //     cout << a[i] << " ";
        // cout << endl;
        //   for(int i=0;i<(int)b.size();i++)
        //     cout << b[i] <<  " ";
        
        int ans=*(b.end()-1);
        // cout << ans << endl;
        for(auto i:a){
            auto temp=upper_bound(b.begin(),b.end(),m-i);
            // cout << i << " " << *(temp-1)<<endl;
            ans=max(ans,(i+*(temp-1))%m);
        }
        cout << ans <<endl;
    }
}