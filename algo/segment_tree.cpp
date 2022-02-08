#include <cstdio>
const int maxn=1e5+10;
int n,m,p,t,x,y,k=0,a[maxn],ans;
typedef long long ll;
struct segtree{
	static const int maxm=4*maxn;
	int i,j,tot,t[maxm][2],v[maxm],sz[maxm],D;
	inline void init(int u){t[u][1]=1,t[u][0]=0;}
	void build(int *a,int n){
		for(D=tot=1;tot<=n+1;D++) tot<<=1;
		for(i=2*tot-1;i;i--) init(i);
		for(i=1;i<=n;i++) v[i+tot]=a[i];
		for(i=0;i<tot;i++) sz[i+tot]=1;
		for(i=tot-1;i;i--) v[i]=v[i<<1]+v[i<<1|1],sz[i]=sz[i<<1]+1;
	}
	int calc(int s){
		return ((ll)v[s]*t[s][1]+t[s][0]*sz[s])%p;
	}
	int passt(int f,int s){
		t[s][0]=t[s][0]*t[f][1]+t[f][0];
		t[s][1]=t[s][1]*t[f][1];
		return calc(s);
	}
	int pushup(int f){
		if(f<tot)
			 return v[f]=v[f<<1]+v[f<<1|1];
		else return calc(f);
	}
	int pushdown(int f){
		int ls=f<<1,rs=f<<1|1,res;
		if(f<tot)
			res=(passt(f,ls)+passt(f,rs))%p;
		else res=v[f]=calc(f);
		init(f);
		return res;
	}
	void downto(int u){
		for(j=u,i=0;j;j>>=1) i++;
		while(i--) pushdown(u>>i);
	}
	void upfrom(int u){
		for(;u;u>>=1) pushup(u);
	}
	int modify(int m,int u,int k,int sz){
		if(m==0)
			t[u][0]+=k;
		else if(m==1)
			for(int i=0;i<2;i++)
				t[u][i]=(ll)t[u][i]*k%p;
		return pushdown(u);
	}
	int query(int t,int L,int R,int k){
		long long res=0;
		int l=tot+L-1,r=tot+R+1,sz=1;
		downto(l);
		downto(r);
		for(;l^r^1;l>>=1,r>>=1,sz<<=1){
			if(~l&1) res+=modify(t,l^1,k,sz);
			if( r&1) res+=modify(t,r^1,k,sz);
		}
		upfrom(l);
		return res%p;
	}
	void print(){
		for(i=0,j=1;j<(tot<<1);j++){
			if(j==1<<i) i++,puts("");
			for(int k=0;k<(1<<(D-i))-1;k++) putchar(' ');
			printf("%d",v[j]);
			for(int k=0;k<(1<<(D-i));k++) putchar(' ');
		}
	}
}st;
int main(){
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	st.build(a,n);
	for(;m--;k=0){
		scanf("%d%d%d",&t,&x,&y);
		if(t!=3) scanf("%d",&k);
		ans=st.query(2-t,x,y,k);
		if(t==3) printf("%d\n",ans);
		st.print();
	}
}
