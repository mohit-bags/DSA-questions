#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int ans=0;
int n;
int grid[3][3];
void solve(int c,int a,int b){
    if(c==n){
        ans++;
        return;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[i][j]==0){
              if((a==-1 && b==-1) || ((a+i)%2==1 || (b+j)%2==1))
              {
                grid[i][j]=1;
                solve(c+1,i,j);
                grid[i][j]=0;
              }
              else if((a+i)%2==0 && (b+j)%2==0 && grid[(a+i)/2][(b+j)/2])
              {
                   grid[i][j]=1;
                    solve(c+1,i,j);
                    grid[i][j]=0;
              }
            }
        }
    }
}
signed main(){
    cin >> n;
    memset(grid,0,sizeof(grid));
    solve(0,-1,-1);
    cout << ans <<endl;
}