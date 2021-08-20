#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

signed main(){
    int t;cin >> t;
    while(t--)
    {
    int n; cin >> n;
    vector<int> A(n);
    int num; cin >> num;
    for(int i=1;i<n;i++)
    {
        cin >> A[i];
        num=num&A[i];
    }
    cout << num << endl;
    }
}