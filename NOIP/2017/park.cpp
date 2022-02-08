#include <cstdio>
#include <queue>
const int maxn=100010,maxm=200010;
int n,m,k,p,a,b,c,i,j,vis[maxn],dis[maxn];
struct graph{
	int h[maxn],n[maxm],v[maxm],w[maxm];
	void clear(){
		memset(h,0,sizeof(h));
		memset(vis,0,sizeof(vis));
	}
	void get(int i,int a,int b,int c){
		v[i]=b,w[i]=c;
		n[i]=h[a],h[a]=i;
	}
	void dijkstra(){
		using namespace std;
		typedef pair<int,int> pii;
		pii tmp;
		priority_queue<pii,vector<pii>,greater<pii> > q;
		q.push({0,1});
		while(!q.empty()){
			tmp=q.top(),q.pop();
			u=tmp.second;
			if(vis[u]) continue;
			for(int i=h[u];i;i=n[i])
				if(!vis[v]||dis[v[i]]>dis[u]+w[i]){
					vis[v]=1;
					dis[v]=dis[u]+w[i];
				}
		}
	}
}pos,neg;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&n,&m,&k,&p);
		for(i=1;i<=n;i++)
			scanf("%d%d%d",&a,&b,&c),
			pos.get(i,a,b,c),
			neg.get(i,b,a,c);
		pos.dijkstra();
		dp();
		printf("%d",f[n][k]);
	}
}
