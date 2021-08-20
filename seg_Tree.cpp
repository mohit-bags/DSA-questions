#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int t[400400];

void build(int id,int l,int r)
{
    if(l==r)
    {
        t[id]=1;
        return;
    }
    int mid=(l+r)/2;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    
    t[id]=t[2*id]+t[2*id+1];
}

void update(int id,int l,int r,int pos,int val)
{
    if(pos<l||pos>r) return;
    if(l==r)
    {
        t[id]=val;
        return;
    }
    int mid = (l+r)/2;
    update(id<<1,l,mid,pos,val);
    update(id<<1|1,mid+1,r,pos,val);
    
    t[id]=t[id<<1]+t[id<<1|1];
}

int query(int id,int l,int r,int x)
{
    if(t[id]<x) return -1;
    if(l==r)
    {
        return l;
    }
    
    int mid = (l+r)/2;
    
    if(t[id<<1]>=x) return query(id<<1,l,mid,x);
    else return query(id<<1|1,mid+1,r,x-t[id<<1]);
    
}

void solve()
{
    int n;
    cin>>n;
//     6
// 5 3 2 6 1 4
//  4 6

// 0 1 2 0 3 2
// 1 3 5 2 6 4
// 
    pair<int,int> a[n];
    int p[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second = i;
    }
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    
    build(1,0,n-1);
    
    int ans[n];
    
    sort(a,a+n);
    
    for(int i=0;i<n;i++)
    {
        int j = a[i].second;
        int pos = query(1,0,n-1,p[j]+1);
        ans[pos]=j;
        update(1,0,n-1,pos,0);
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]+1<<" ";
    }
    cout<<endl;
    
}

int main() {
	// your code goes here
	solve();
	return 0;
}