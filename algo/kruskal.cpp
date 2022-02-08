#include <cstdio>
#include <algorithm>
const int maxn=5010,maxm=200010;
int m,n,i,j,f[maxn];
long long res=0,num=0;
struct edge{
	int u,v,w;
	void scan(){scanf("%d%d%d",&u,&v,&w);}
	bool operator < (const edge &e) const{return w<e.w;}
}e[maxm];
void init(){for(int i=0;i<=n;i++) f[i]=-1;}
int find(int i){return f[i]<0?i:f[i]=find(f[i]);}
bool uion(int i,int j){
	int fi=find(i),fj=find(j);
	if(fi==fj) return 0;
	if(fi>fj) std::swap(fi,fj);
	f[fi]+=f[fj],f[fj]=fi;
	return find(i)==find(j);
}
void kruskal(edge *e,int n,int m){
	std::sort(e,e+m);
	init();
	for(i=0;i<m;i++)
		if(uion(e[i].u,e[i].v))
			res+=e[i].w,num++;
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++) e[i].scan();
	kruskal(e,n,m);
	if(num==n-1) printf("%lld\n",res);
	else printf("orz\n");
}
