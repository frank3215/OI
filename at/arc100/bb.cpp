#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<utility>
#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
const int maxn = 2e5 + 233;
typedef long long ll;
ll pre[maxn],suf[maxn],a[maxn];
int k1[maxn],k2[maxn];
bool check(ll s1,ll s2,int v)
{
	ll t1 = abs(s1-s2-s2);
	s2 += v;
	ll t2 = abs(s1-s2-s2);
	if(t2<t1)return 1;
	return 0;
}
int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		a[i] = x;
	}
	pre[0] = 0;
	int j = 0;
	for(int i=1;i<=n;i++)
	{
		pre[i] = pre[i-1] + a[i];
		while(check(pre[i],pre[j],a[j+1]))j++;
		k1[i] = j;
	}
	j = n+1;
	a[n+1] = suf[n+1] = 0;
	for(int i=n;i;i--)
	{
		suf[i] += suf[i+1] + a[i];
		while(check(suf[i],suf[j],a[j-1]))j--;
		k2[i] = j;
	}
	ll ans = 1LL<<60;
	for(int i=2;i<n-1;i++)
	{
		a[1] = pre[k1[i]];
		a[2] = pre[i]-pre[k1[i]];
		a[3] = suf[i+1]-suf[k2[i+1]];
		a[4] = suf[k2[i+1]];
/*		cout<<i<<"************"<<endl;
		cout<<k1[i]<<" "<<k2[i+1]<<" "<<endl;
		cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<endl;*/
		sort(a+1,a+5);
		ans = min(ans,a[4]-a[1]);
	}
	cout << ans << endl;
	return 0;
}

