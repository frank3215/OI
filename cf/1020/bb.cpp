#include <cstdio>
const int maxn=1010;
int n,a[maxn],ans[maxn],vis[maxn],loop=0,i;
int dfs(int u){
	if(vis[u]){
		if(ans[u]) return ans[u];
		else return loop=ans[u]=u;
	}
	vis[u]=1;
	int tmp=dfs(a[u]);
	if(loop==u) loop=0;
	if(loop) ans[u]=u;
	else ans[u]=tmp;
	return tmp;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<=n;i++){
		loop=0;
		printf("%d ",dfs(i));
	}
}
