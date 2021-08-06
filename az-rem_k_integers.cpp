#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
signed main(){
    int t; cin  >> t;
    while(t--){
        deque<int> dq;
        dq.clear();
        int n,k;
        cin>> n>>k;
        int arr[n];
        int diff[n-1];
        for(int i=0;i<n;i++)
            cin >> arr[i];
        for(int i=0;i<n-1;i++)
        {
            diff[i]=arr[i+1]-arr[i];
            if(i<n-k-1)
            {
                while(!dq.empty() && diff[i]>=diff[dq.back()])
                    dq.pop_back();
                dq.push_back(i);
            }
        }
        int maxx=INT_MAX;
        int window = n-k-1;
        int i= window;
        while(i<n-1){
            maxx=min(maxx,diff[dq.front()]);
            while(!dq.empty() && dq.front()<=i-window)
                dq.pop_front();
             while(!dq.empty() && diff[i]>=diff[dq.back()])
                 dq.pop_back();
            dq.push_back(i);
            i++;
        }
        maxx=min(maxx,diff[dq.front()]);
        cout << maxx<<endl;
    }
}
