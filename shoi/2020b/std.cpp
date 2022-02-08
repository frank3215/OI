#include<bits/stdc++.h>
using namespace std;
const int N=2505;
int n,m,s,x,y,ans,f[N],fa[N],d[N];
vector<pair<int,int> > g[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int x,int y){fa[find(x)]=find(y);}
int work(int t)
{
	int ss=0,la=0,ans=0;
	d[s]++,d[t]++;
	for(int i=1;i<=n;i++)fa[i]=f[i],g[i].clear();
	for(int i=1;i<n;i++)
	{
		ss+=d[i];
		if(ss&1)ans++,merge(i,i+1);
	}
	for(int i=1;i<=n;i++)
		if(d[i])
		{
			if(la && find(i)!=find(la))g[i-la].push_back(make_pair(la,i));
			la=i;
		}
	for(int i=1;i<=n;i++)
		for(auto x:g[i])
		{
			if(find(x.first)!=find(x.second))
				ans+=2*i,merge(x.first,x.second);
		}
	d[s]--,d[t]--;
	return ans;
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		d[x]++,d[y]++;
		merge(x,y);
		ans+=abs(x-y);
	}
	for(int i=1;i<=n;i++)f[i]=fa[i];
	for(int i=1;i<=n;i++)
		printf("%d ",work(i)+ans);
}
