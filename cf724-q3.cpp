#include <bits/stdc++.h>
#define int long long int
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<int> countfreq(string s){
    vector<int> carr(5,0);
    for(int i=0;i<s.length();i++)
        carr[s[i]-'a']++;
    return carr;
}

signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<string> vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];

        int arr[5][n];
        int diff[5][n];
        for(int i=0;i<n;i++){
            vector<int> tmp=countfreq(vec[i]);
            for(int j=0;j<5;j++)
            {
                arr[j][i]=tmp[j];
                diff[j][i]=2*tmp[j]-vec[i].length();
            }
        }
        // arr[0] ---> has a count   
        int mxwords=0;
        for(int i=0;i<5;i++)
        {
            sort(diff[i],diff[i]+n,greater<int>());
            
            int sum=0;
            int tmpw=0;
            for(int j=0;j<n && sum>=0;j++){
                if(sum+diff[i][j]>0)
                {
                    sum+=diff[i][j];
                    tmpw++;
                    // cout << tmpw << endl;
                }
                else
                    break;
            }
            mxwords=max(mxwords,tmpw);
        }
        cout << mxwords << endl;
    }
}