
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
signed main()
{
    int n; cin >> n;
    vector<int> factor1;
    vector<int> factor2;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            factor1.push_back(i);
            if(i!=(n/i))
                factor2.push_back(n/i);
        }
    }
    for(int i=0;i<factor1.size();i++)
        cout << factor1[i] << " ";
    for(int i=factor2.size()-1;i>=0;i--)
        cout << factor2[i] << " ";
    return 0;
}