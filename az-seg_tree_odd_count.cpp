#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define N 100010
int arr[N];
int t[4*N];
int query(int l,int r,int lq,int rq,int ind){
    if(l>rq || r<lq)
        return 0;
    if(lq<=l && r<=rq){
        return t[ind];
    }
    int mid=(l+r)/2;
    return query(l,mid,lq,rq,2*ind)+query(mid+1,r,lq,rq,2*ind+1);
}
void update(int pos,int l,int r,int x,int ind){
    if(pos<l || pos>r)
        return;
    if(l==r){
        arr[pos]=x;
        t[ind]=x%2;
        return;
    }
    int mid=(l+r)/2;
    update(pos,l,mid,x,2*ind);
    update(pos,mid+1,r,x,2*ind+1);
    t[ind]=t[2*ind]+t[2*ind+1];
}
void build(int ind,int l,int r){
    if(l==r){
        t[ind]=arr[l]%2; // kept count of odd
        return;
    }
    int mid=(l+r)/2;
    build(2*ind,l,mid);
    build(2*ind+1,mid+1,r);
    t[ind]=t[2*ind]+t[2*ind+1];
}
signed main(){
    int n; cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    build(1,0,n-1);
    int q; cin >> q;
    while(q--){
        int opt; cin >> opt;
        if(opt==0){
            int ind,x;
            cin >> ind >> x;
            ind--;
            update(ind,0,n-1,x,1);
        }
       else if(opt==2){
            int l,r;
            cin >> l >> r;
            l--,r--;
            cout << query(0,n-1,l,r,1)<<endl;
        }
        else{
             int l,r;
            cin >> l >> r;
            l--,r--;
            cout << (r-l+1)-query(0,n-1,l,r,1)<<endl;
        }
    }
}