#include <cstdio>
#include <stack>
#include <vector>
using std::min;
const int maxm=100010,maxn=20010;
int n,m,i,j,u,v,tot=0,ans=0,
	head[maxn]={},to[maxm*2],next[maxm*2],
	dfn[maxn],low[maxn],vis[maxn];
std::stack<int> s;
void tarjan(int u){
	dfn[u] = low[u] = ++tot;
	s.push(u), vis[u] = 1;
	int v,b=0;
	for(int i = head[u]; i; i = next[i]){
		v = to[i];
		if (!dfn[v])
			tarjan(v),
			low[u] = min(low[u], low[v]);
		else if (vis[v])
			low[u] = min(low[u], dfn[v]);
	}
	//printf("%d %d %d\n",u,dfn[u],low[u]);
	if(dfn[u] == low[u]) do{
		vis[v=s.top()]=0,s.pop();
		if(v!=u) b=1;
	}while(v!=u);
	ans+=b;
}
inline void con(int u, int v) {
	to[++tot]=v,
	next[tot]=head[u],
	head[u]=tot;
}
int main() {
	scanf("%d%d", &n, &m);
	for (i=0;i<m;i++)
		scanf("%d%d", &u, &v),
		con(u, v);//, con(v, u);
	tot=0;
	for (i=1;i<=n;i++)
		if (!dfn[i])
			tarjan(i);
	printf("%d\n",ans);
}

