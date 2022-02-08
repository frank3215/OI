#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,a[25];

ll get(int l,int r,ll L,ll R)
{
	if (l+1==r) return L*a[l]+R*a[r];
	ll ans=1e18;
	for (int i=l+1;i<r;i++)
		ans=min(get(l,i,L,L+R)+get(i,r,L+R,R)-a[i]*(L+R),ans);
	return ans;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	printf("%lld\n",get(1,n,1,1));
}

