#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<int> cols;
int n;
int ans=0;
bool check(int row,int col){
    for(int i=0;i<(int)cols.size();i++){
        int pcol=cols[i];
        if(col==pcol || abs(pcol-col)==abs(row-i))
            return false;
        else if(abs(i-row)==1 && abs(pcol-col)==2)
            return false;
        else if(abs(i-row)==2 && abs(pcol-col)==1)
            return false;
    }
    return true;
}
void solve(int row){
    if(row==n){
        ans++;
        return;
    }
    for(int i=0;i<n;i++){
        if(check(row,i)){
            cols.push_back(i);
            solve(row+1);
            cols.pop_back();
        }
    }
    return ;
}

signed main(){
    IOS;
    cin >> n;
    solve(0);
    cout << ans;
}