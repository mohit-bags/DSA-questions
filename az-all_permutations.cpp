#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define N 1000001

signed main(){
    IOS;
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >>arr[i];
    sort(arr.begin(),arr.end());
    vector<int> temp=arr;
    vector<vector<int>> vec;
    do{
        vec.push_back(temp);
        next_permutation(temp.begin(),temp.end());
    }while(temp!=arr);
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<arr.size();j++)
            cout << vec[i][j]<<" ";
        cout << endl;
    }
}