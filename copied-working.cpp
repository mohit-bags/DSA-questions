#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int cntDist=0;
void insert(ll a)
{
	if(a%2!=0) cntDist++;
}
void remove(ll a)
{
	if(a%2!=0) cntDist--;
}
signed main()
{
	IOS;
	ll t;
	cin>>t;
	// memset(freq,0,sizeof(freq));
	while(t--)
	{
		ll n,k,d,i,head=-1,tail=0,oddcnt=0;
		cin>>n>>k>>d;
		ll a[n],pre[n],maxsum=-1e18,start;
		multiset<ll> mt;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			pre[i]=a[i];
			if(i) pre[i]+=pre[i-1];
		}
		while(tail<n)
		{
			while(head+1<n && (oddcnt<k ||(oddcnt==k && a[head+1]%2==0)))
			{
				head++;
				if(a[head]%2) oddcnt++;
				mt.insert(pre[head]);
			}
			start= tail==0?0:pre[tail-1];
			auto it = mt.upper_bound(start+d);
			if(it!=mt.begin())
			{
				it--;
				maxsum = max(maxsum,*it-start);
			}
			if(tail>head)
			{
				tail++;
				head=tail-1;
			}
			else
			{
				if(a[tail]%2) oddcnt--;
				mt.erase(mt.find(pre[tail]));
				tail++;
			}
		}
		if(maxsum==-1e18) cout<<"IMPOSSIBLE\n";
		else cout<<maxsum<<endl;
	}
	return 0;
}

