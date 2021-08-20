#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define N 1000001

vector<int> generate(vector<int> vec)// all pair sums
{
    int n=vec.size();
    vector<int> st;
    for(int i=0;i<(1<<n);i++){
        int sum=0;
        for(int j=0;j<n;j++){
            if((i>>j)&1)
            {
                sum+=vec[j];
            }
        }
        st.push_back(sum);
    }
    return st;
}
signed main(){
    IOS;
    int t;cin>>t;
    while(t--){
        
        int n,x; cin >> n>>x;
        vector<int> vec[2];
        for(int i=0;i<n;i++){
            int in; cin >> in;
            vec[i&1].push_back(in);
        }
        vector<int> a=generate(vec[0]);
        vector<int> b=generate(vec[1]);
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int ans=0;
        for(auto i :a){
            ans+=(upper_bound(b.begin(),b.end(),x-i)-b.begin());
        }
        cout << ans << endl;
    }

}