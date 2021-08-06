#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int ans=0;
bool vis[7][7];
string s;
bool isvalid(int x,int y){
    return (x>=0 && x<7 && y>=0 && y<7);
}
void solve(int i,int x,int y){
    if(i==s.length() && x==6 && y==0)
    {
        ans++;
        return;
    }
    int dx[]={0,-1,1,0};
    int dy[]={1,0,0,-1};
    for(int j=0;j<4;j++){
        int X=x+dx[j];
        int Y=y+dy[j];
     if(isvalid(X,Y) && s[i]=='?' && !vis[X][Y]){
            vis[X][Y]=true;
            solve(i+1,X,Y);
            vis[X][Y]=false;
            }
        else if(isvalid(X,Y) &&s[i]=='L' && j==3 && !vis[X][Y]){
            vis[X][Y]=true;
            solve(i+1,X,Y);
            vis[X][Y]=false;
            }
        else if(isvalid(X,Y) &&s[i]=='R' && j==0 &&!vis[X][Y]){
            vis[X][Y]=true;
            solve(i+1,X,Y);
            vis[X][Y]=false;
            }
        else if(isvalid(X,Y) &&s[i]=='U' && j==1 &&  !vis[X][Y]){
            vis[X][Y]=true;
            solve(i+1,X,Y);
            vis[X][Y]=false;
            }
        else if(isvalid(X,Y) &&s[i]=='D' && j==2 &&  !vis[X][Y]){
            vis[X][Y]=true;
            solve(i+1,X,Y);
            vis[X][Y]=false;
        }
    }
    return;
}
signed main(){
    IOS;
    cin >> s;
    memset(vis,false,sizeof(vis));
    vis[0][0]=true;
    solve(0,0,0);
    cout << ans;
}
