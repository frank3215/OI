#include <cstdio>
long long dfs(int u,int f){
	for(int i=head[u];i;i=next[i])
		a[u]+=dfs(to[i],u);
	return a[u];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%I64d",a+i);
	for(int i=2,j;i<=n;i++){
		scanf("%d",j);
		con(i,j),con(j,i);
	}
	dfs(1,0);
	for(int i=n;i;i--)
		if(a[1]%i)
}
