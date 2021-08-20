#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

signed main(){
    IOS;
    int t;cin>>t;
    while(t--){
        int n,x; cin >> n>>x;
        vector<int> vec(n);
        int c=0;
        for(int i=0;i<n;i++){
            cin>>vec[i];
            if(i && vec[i]<vec[i-1])c++;
        }
        c++;
        if(c<=x)
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;
    }
}
// #include <bits/stdc++.h>
// #define int long long int
// using namespace std;
// signed main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//          int n,k;
//         cin>>n>>k;
//         vector<int> A(n);
//         for(int i=0;i<n;i++)
//         {
//             cin>>A[i];
//         }
//         int ans=1;
//         for(int i=1;i<n;i++)
//         {
//             if(A[i]>=A[i-1])continue;
//             else
//             {
//                 ans++;
//             }
//         }
//         if(ans<=k)cout<<"Yes"<<endl;
//         else cout<<"No"<<endl;
//     }
// }
        