#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define N 200020
struct node{
    int totsum,lsum,rsum,maxsum;
    node(int a=0,int b=0,int c=0,int d=0){
        totsum=a;
        lsum=b;
        rsum=c;
        maxsum=d;
    }
};
node merge(node a,node b){
    node c= node();
    c.maxsum=max(a.maxsum,max(b.maxsum,(a.rsum+b.lsum)));
    c.lsum=max(a.lsum,(a.totsum+b.lsum));
    c.rsum=max(b.rsum,(b.totsum+a.rsum));
    c.totsum=a.totsum+b.totsum;
    return c;
}
int arr[N];
node t[4*N];
int query(int l,int r,int lq,int rq,int ind){
    if(l>rq || r<lq)
        return 0;
    if(lq<=l && r<=rq){
        return t[ind].maxsum;
    }
    int mid=(l+r)/2;
    return query(l,mid,lq,rq,2*ind)+query(mid+1,r,lq,rq,2*ind+1);
}
void update(int pos,int l,int r,int x,int ind){
    if(pos<l || pos>r)
        return;
    if(l==r){
        arr[pos]=x;
        t[ind]=node(x,max(0LL,x),max(0LL,x),max(0LL,x));
        return;
    }
    int mid=(l+r)/2;
    update(pos,l,mid,x,2*ind);
    update(pos,mid+1,r,x,2*ind+1);
    t[ind]=merge(t[2*ind],t[2*ind+1]);
}
void build(int ind,int l,int r){
    if(l==r){
        int tmp=max(0LL,arr[l]);
        t[ind]=node(arr[l],tmp,tmp,tmp); // kept count of odd
        return;
    }
    int mid=(l+r)/2;
    build(2*ind,l,mid);
    build(2*ind+1,mid+1,r);
    t[ind]=merge(t[2*ind],t[2*ind+1]);
}
signed main(){
    int n,q; cin >> n>>q;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    build(1,0,n-1);
    while(q--){
            int ind,x;
            cin >> ind >> x;
            ind--;
            update(ind,0,n-1,x,1);
            cout << query(0,n-1,0,n-1,1)<<endl;
     
    }
}