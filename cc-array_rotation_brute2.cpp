#include<bits/stdc++.h>
using namespace std;
typedef int long long ;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define N 1000001


void return_best(vector<int> &A,vector<int> &B,vector<int> temp,int ith){
    int n=A.size();
    int num=A[ith];
    int mn_val=LLONG_MAX;
    vector<int> temp_ind;
    for(int i=0;i<temp.size();i++)
    {
        int temp_val=(B[(ith+temp[i])%n]+num)%n;
        if(temp_val<mn_val){
            temp_ind.clear();
            mn_val=temp_val;
            temp_ind.push_back(temp[i]%n);
        }
        else if(temp_val==mn_val){
            temp_ind.push_back(temp[i]%n);
        }
    }
    
    if((int)temp_ind.size()==1LL || ith==n)
    {
        // cout << temp_ind[0]<<endl;
        for(int i=0;i<n;i++)
        {
            int AI = i;
            int BI = (temp_ind[0]+i)%n;
            cout << (A[AI]+B[BI])%n << " ";
        }
        return ;
    }
    else{
        return_best(A,B,temp_ind,ith+1);
    }
}

signed main(){
    IOS;
    int t;cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> A(n),B(n);
        for(int i=0;i<n;i++) cin >> A[i];
        for(int i=0;i<n;i++) cin >> B[i];
        vector<int> B_ind;
        for(int i=0;i<n;i++)
            B_ind.push_back(i);

        return_best(A,B,B_ind,0);

        
    }
    return 0;
}