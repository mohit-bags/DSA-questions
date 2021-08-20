#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define N 1000001
ll vec[200010];
ll t[800040];


void update(int i,int x,int l, int r){
    if(l==r){
        t[i]=x;
        return;
    }
    int mid=(l+r)/2;
    update(2*i,x,l,mid);
    update(2*i+1,x,mid+1,r);
    t[i]=t[2*i]+t[2*i+1];
}

void build(int ind,int l,int r){
    if(l==r){
        t[ind]=vec[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*ind,l,mid);
    build(2*ind+1,mid+1,r);
    t[ind]=t[2*ind]+t[2*ind+1];
}

int main(){
    int n,q;
    cin >> n >> q;
    
    for(int i=0;i<n;i++)
        cin >> vec[i];

    build(0,n-1);

    while(q--){
        int opt; cin >> opt;
        if(opt==1){
            int ind,x;
            update(ind,x);
        }
        else{
            int l,r;
            cin >> l >> r;
            query(l,r,0,n-1);
        }
    }
}