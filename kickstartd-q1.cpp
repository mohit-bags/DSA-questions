#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int arr[3][3];

int count(int num){
    int count=0;
    if(arr[0][0]+arr[2][2]==2*num) //D
        count++;
     if(arr[0][2]+arr[2][0]==2*num) //D
        count++;
     if(arr[1][0]+arr[1][2]==2*num) //R
        count++;
     if(arr[0][1]+arr[2][1]==2*num) //C
        count++;
    return count;
}
signed main(){
    boost;
    int t; cin >> t;
    for(int _=1;_<=t;_++){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++){
                if(i==1 && j==1) continue;
                cin >> arr[i][j];

        }
    
    int mxc=0;
    //ROW
    int mid=arr[1][0]+arr[1][2];
    if(mid%2==0){
        mxc=max(mxc,count(mid/2));
    }
    mid=arr[0][1]+arr[2][1];
    if(mid%2==0){
        mxc=max(mxc,count(mid/2));
    }
    mid=arr[0][2]+arr[2][0];
    if(mid%2==0){
        mxc=max(mxc,count(mid/2));
    }
    mid=arr[0][0]+arr[2][2];
    if(mid%2==0){
        mxc=max(mxc,count(mid/2));
    }
    //top row check
    if(arr[0][1]*2==arr[0][0]+arr[0][2])
        mxc++;
    if(arr[1][0]*2==arr[0][0]+arr[2][0]) //lc
        mxc++;
    if(arr[1][2]*2==arr[0][2]+arr[2][2]) //rc
        mxc++;
    if(arr[2][1]*2==arr[2][0]+arr[2][2]) //bottom wrow
        mxc++;
    
    cout << "Case #"<<_<<": "<<mxc<<endl;
}
}
