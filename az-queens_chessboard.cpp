#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int ans=0;
vector<int> cols;
bool reserved[8][8];

bool check(int row,int col){
    for(int i=0;i<row;i++){
        //(abs(cols[i]-col)==abs(i-row)
        if( col==cols[i] || (row-col==i-cols[i]) || (row+col==i+cols[i]))
                return false;
        }
    return true;
}
void solve(int row){
    if(row==8)
    {
        ans++;
        return;
    }
    for(int j=0;j<8;j++){
        if(!reserved[row][j] &&check(row,j))
        {
            cols.push_back(j);
            solve(row+1);
            cols.pop_back();
        }
    }
}

signed main(){
    IOS;
    memset(reserved,false,sizeof(reserved));
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++)
            {
                char ch; cin >> ch;
                if(ch=='*')reserved[i][j]=true;
            }
    }

     for(int i=0;i<8;i++){
        for(int j=0;j<8;j++)
            cout << reserved[i][j];
        cout << endl;}
    solve(0);
    cout << ans << endl;
}