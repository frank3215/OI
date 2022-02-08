#include <bits/stdc++.h>
#define N 1005
#define M 200005
using namespace std;

int n,m;
bool irp[N][N],lnk[N][N];
int rt,cnt,fir[N];
bool col[N];
vector<int>to[N];
struct edge{int u,v;}e[M];

inline int read()
{
	int ans=0,f=1;char c=getchar();
	while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') ans=(ans<<1)+(ans<<3)+(c^48),c=getchar();
	return ans*f;
}

inline void add(int a,int b){to[a].push_back(b);e[++cnt]=(edge){a,b};}

inline void dfs(int x)
{
	col[x]=lnk[rt][x]=1;
	for(auto it:to[x]) if(!col[it]) dfs(it);
}

inline void insert(int x)
{
	rt=x;
	memset(col+1,0,n*sizeof(col[0]));
	col[x]=1;
	for(auto it:to[x])
		if(col[it]) irp[x][it]=1;
		else dfs(it);
	reverse(to[x].begin(),to[x].end());
	memset(col+1,0,n*sizeof(col[0]));
	col[x]=1;
	for(auto it:to[x])
		if(col[it]) irp[x][it]=1;
		else dfs(it);
}

int main()
{
//	freopen("test.in","r",stdin);
	n=read(),m=read();
	for(int i=1;i<=m;++i)
	{
		int a=read(),b=read();
		add(a,b);
	}
	for(int i=1;i<=n;++i)insert(i);
	for(int i=1;i<=m;++i)
	{
		int x=e[i].u,y=e[i].v;
		puts(irp[x][y]^lnk[y][x]?"diff":"same");
	}
}

