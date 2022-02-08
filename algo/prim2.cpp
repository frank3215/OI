#include <cstdio>
using namespace std;
#define inf 0x7fffffff
#define maxn 5005
int cost[maxn][maxn],minn,n,m,v2[maxn],tot=1,now,ans;
bool v1[maxn];
inline int prim()
{
	while(tot++<n){
		minn=inf;
		for(int i=1;i<=n;i++)
			if(!v1[i]&&v2[i]<minn)
				minn=v2[i],now=i;
		ans+=minn;
		for(int i=1;i<=n;i++)
			if(v2[i]>cost[now][i]&&!v1[i])
				v2[i]=cost[now][i];
		v1[now]=1;
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cost[i][j]=inf;
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		if(cost[u][v]>w)
			cost[u][v]=cost[v][u]=w;
	}
	for(int i=1;i<=n;i++)
		v2[i]=cost[1][i];
	v1[1]=1;
	printf("%d",prim());
	return 0;
}