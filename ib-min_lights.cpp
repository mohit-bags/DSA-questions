#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int solve(vector<int> &A, int B) {
    int n=A.size();
    int c=0;
    for(int i=0;i<n;i++){
        int flag=0;
        for(int j=i+B-1;j>=i-B+1;j--){
            if(A[j]==1){
                flag=1;
                i=j+B;
                c++;
                break;
            }
        }
        if(flag==0)
            return -1;
    }
    return c;
}

signed main(){
    int n,B; cin >> n>>B;
    vector<int> A(n);
    for(int i=0;i<n;i++)
        cin >> A[i];
    cout << solve(A,B)<<endl;
}