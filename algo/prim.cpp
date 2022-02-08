#include <cstdio>
#include <queue>
const int maxn=5010,maxm=200010;
int num,vis[maxn]={},m,n,i,j,u,v,w;
long long res;
struct node{
	int data;
	struct edge* first;
}V[maxn];
struct edge{
	int from,to,weight;
	edge* next;
	void add(int u,int v,int w){
		from=u,to=v,weight=w;
		next=V[from].first;
		V[from].first=this;
	}
	bool operator < (const edge &e) const{return weight>e.weight;}
}e[2*maxm];
std::priority_queue<edge> q;
void prim(edge *e,int n,int m){
	q.push((edge){0,1,0});
	while(1){
		while((!q.empty())&&vis[q.top().to])
			q.pop();
		if(q.empty()) break;
		edge d = q.top();
		vis[d.to]++;
		num++,res+=d.weight;
		for(edge *g=V[d.to].first;g;g=g->next)
			if(!vis[g->to])
				q.push(*g);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
		scanf("%d %d %d",&u,&v,&w),
		e[2*i].add(u,v,w),
		e[2*i+1].add(v,u,w);
	prim(e,n,m);
	if(num==n) printf("%lld\n",res);
	else printf("orz\n");
}
