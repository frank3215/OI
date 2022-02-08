#include<cstdio>
const int maxn=500010,maxm=500010;
int n,k,m,fa[maxn];
int find(int i){return fa[i]==i?i:fa[i]=find(fa[i]);}
struct edge{int to,ty;edge*next;}E[maxn*2],*ne=E,*fir[maxn];
void link(int u,int v,int ty){*ne=(edge){v,ty,fir[u]};fir[u]=ne++;}
void link2(int u,int v,int ty){link(u,v,ty);link(v,u,ty);}
int a[maxm],b[maxm],val[maxm],cnt;
int f[maxn],d[maxn],res[maxn];
void dfs(int i){
	for(edge*e=fir[i];e;e=e->next)if(e->to!=f[i]){
		f[e->to]=i;
		d[e->to]=d[i]+1;
		dfs(e->to);
	}
}
int main(){
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=n;i++)fa[i]=i;
	while(k--){
		int u,v;scanf("%d%d",&u,&v);
		fa[find(u)]=find(v);
		link2(u,v,0);
	}
	while(m--){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		if(find(u)==find(v)){
			a[cnt]=u;b[cnt]=v;val[cnt++]=w;
		}
		else fa[find(u)]=find(v),link2(u,v,1);
	}
	dfs(1);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=0;i<cnt;i++){
		int u=find(a[i]),v=find(b[i]);
		while(u!=v){
			if(d[u]>d[v])res[u]=val[i],fa[u]=find(f[u]),u=fa[u];
			else res[v]=val[i],fa[v]=find(f[v]),v=fa[v];
//解说：res[u]=weight(u,f[u]); 这个过程相当于左右节点一节一节向上跳（类树链剖分）
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
		for(edge*e=fir[i];e;e=e->next)
			if(e->to==f[i]&&!e->ty){
				if(fa[i]==i)return puts("-1"),0;
				ans+=res[i];
			}
	printf("%lld\n",ans);
}

