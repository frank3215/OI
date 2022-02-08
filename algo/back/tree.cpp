#include <cstdio>
#include <algorithm>
int f[61][32010],n,m,v[61],p[61],q[61],cost[61],val[61],head[61]={},to[61],nex[61],tot=0,i,ans=0;
void dp(int u){
	tot++;
	val[u]=(cost[u]=v[u])*p[u];
	for(int i=head[u],s; i; i=nex[i]) {
		dp(s=to[i]);
		for(int i=0; i<=n; i++)
			f[tot][i] = std::max(f[tot+1][i],f[tot][i]);
		cost[u]+=cost[s];
		val[u]+=val[s];
	}
	printf("(%d:%d,%d)\n",u,cost[u],val[u]);
	for(int i=n;i>=cost[u];i--)
		f[tot][i] = std::max(f[tot][i], val[u]);
	for(int i=0;i<=n;i++)
		printf("%d ",f[tot][i]);
	puts("");
	tot--;
}
int main()
{
	freopen("inp","r",stdin);
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) {
		scanf("%d%d%d",&v[i],&p[i],&q[i]);
		to[++tot]=i,nex[tot]=head[q[i]],head[q[i]]=tot;
	}
	tot=0;
	dp(0);
	for(i=0;i<=n;i++)
		ans = std::max(ans,f[1][i]);
	printf("%d",ans);
}
