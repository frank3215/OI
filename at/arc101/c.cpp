#include <cstdio>
const int maxn=10010;
int h[maxn],n[maxn],v[maxn],s[maxn],vis[maxn],n,t=0,x,y,vise[maxn];
void con(int x,int y){
	v[++t]=y,n[t]=h[x],h[x]=t;
}
int dfs1(int u,int f){
	s[u]=vis[u]=1;
	for(int i=h[u];i;i=n[i])
		if(v[i]!=f && !vis[v[i]])
			s[u]+=dfs1(v[i],u);
	if(f&&!s[u]%2) x=u,y=f;
	return s[u];
}
int dfs2(int x,int y){
	
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++)
		scanf("%d%d",&x,&y),
		con(x,y),con(y,x);
	dfs1(1,0);
	dfs2(x,y);
}
