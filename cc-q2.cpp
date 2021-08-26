#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int mas;
string brute(vector<string> left,string ans,int in){
    int n=left.size();
    if(n==0 || in==mas)
        return ans;
    vector<string> newleft_0;
    vector<string> newleft_1;

    for(int i=0;i<n;i++){
        if(left[i][in]=='1')
            newleft_1.push_back(left[i]);
        else 
            newleft_0.push_back(left[i]);
    }
    int n1=newleft_1.size();
    int n0=newleft_0.size();
    if(n0>=n1)
        return brute(newleft_1,ans+'1',in+1);
    else
        return brute(newleft_0,ans+'0',in+1);
}
signed main(){
    boost;
    int t; cin >> t;
    while(t--){
        int n;
        cin >> n;
        mas=n;
        vector<string> vec(n);
        for(int i=0;i<n;i++)
            cin >> vec[i];
        
        string ans=brute(vec,"",0);
        while(ans.length()<n){
            ans+='1';
        }
    
        cout <<  ans << endl; 
    }
}