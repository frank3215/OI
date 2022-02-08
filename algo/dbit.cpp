#include <cstdio>
const int maxn=2e7,inf=1e9+10;
int n,a;
long long ans=0;
struct trieBIT{
	int t[maxn],s[maxn][2],res,i,u,tot;
	trieBIT(){tot=1;}
	inline int son(int u,bool n,bool w=0){
		return s[u][n]||w?s[u][n]:s[u][n]=++tot;
	}
	int query(int x){
		for(res=0,u=1,i=1<<31;x&&u;x^=x&i,i>>=1){
			res+=t[u=son(u,x&i,1)];
			//printf("(%d %d)\n",res,u);
		}
		return res;
	}
	void add(int x,int k=1){
		for(u=1,i=1<<31;x;x^=x&i,i>>=1){
			if(!(x&i)) t[son(u,1)]+=k;
			u=son(u,x&i);
		}
		t[u]+=k;
	}
	void print(int u=1,int x=0){
		if(!u) return;
		printf("%d,%d(",x,t[u]);
		print(son(u,0,1),0);
		print(son(u,1,1),1);
		printf(")");
	}
}t;
struct dynamicBIT{
	int t[maxn],s[maxn][2],res,i,u,tot;
	inline int lb(int x){return x&-x;}
};
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		t.add(inf-a);
		ans+=t.query(inf-a-1);
	}
	printf("%lld",ans);
}
