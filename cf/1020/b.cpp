#include <cstdio>
#include <cstring>
const int maxn=1e3+10;
int n,vis[maxn],p[maxn];
int dfs(int u){
	if(vis[u]) return u;
	else{
		vis[u]=1;
		return dfs(p[u]);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",p+i);
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		printf("%d ",dfs(i));
	}
	puts("");
}
