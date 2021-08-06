#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define N 1000001

vector<int> get_mod(vector<int> &A,vector<int> &B){
    vector<int> temp;
    for(int i=0;i<(int)A.size();i++){
        temp.push_back((A[i]+B[i])%(int)A.size());
    }
    return temp;
}
vector<int> rotate(vector<int> temp){
    for(int i=0;i<(int)temp.size()-1;i++)
        swap(temp[i],temp[i+1]);
    return temp;
}

signed main(){
    IOS;
    int t;cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> A(n),B(n);
        for(int i=0;i<n;i++) cin >> A[i];
        for(int i=0;i<n;i++) cin >> B[i];
        vector<vector<int>> C;
        for(int i=0;i<n;i++){
            vector<int> temp=get_mod(A,B);
            C.push_back(temp);
            B=rotate(B);
        }
        stable_sort(C.begin(),C.end());
        for(int i=0;i<n;i++)
            cout << C[0][i] << " ";
        cout << "\n";
    }
}
