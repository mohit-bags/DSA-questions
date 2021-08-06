#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n;
vector<string> lists;
string s;

void solve(int open,int len){
    if(len==n){
        if(open==0)
            lists.push_back(s);
        return;
    }

    s+='(';
    solve(open+1,len+1);
    s.pop_back();
    if(open>0){
    s+=')';
    solve(open-1,len+1);
    s.pop_back();
    }
    
}

signed main(){
    IOS;
    cin >> n;
    solve(0,0);
    for(int i=0;i<(int)lists.size();i++){
        cout << lists[i] << endl;
    }
}