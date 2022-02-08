#include <cstdio>
const int maxn=100007;
int a[maxn],n,m,t,x,y,k;
struct segtree{
	long long N,val[maxn<<2],tag[maxn<<2];
	void build(int *a,int n){
		for(N=1;N<n+2;) N <<= 1;
		for(int i=1;i<=n;++i) val[N+i]=a[i];
		for(int i=N-1;i>0;--i){
			val[i]=val[i<<1]+val[i<<1|1];
			tag[i]=0;
		}
	} 
	void pushup(int u){
		if(u<N) val[u]=val[u<<1]+val[u<<1|1];
	}
	void update(int l,int r,int c){
		int s,t,x=1;
		for(s=N+l-1,t=N+r+1;s^t^1;s>>=1,t>>=1,x<<=1){
			pushup(s);
			pushup(t);
			if(~s&1) tag[s^1]+=c,val[s^1]+=c*x;
			if( t&1) tag[t^1]+=c,val[t^1]+=c*x;
		}
		for(;s;s>>=1,t>>=1){
			pushup(s);
			pushup(t);
		}
	}
	long long query(int l,int r){
		long long s,t,Ln=0,Rn=0,x=1,ans=0;
		for(s=N+l-1,t=N+r+1;s^t^1;s>>=1,t>>=1,x<<=1){
			if(tag[s]) ans+=tag[s]*Ln;
			if(tag[t]) ans+=tag[t]*Rn;
			if(~s&1) ans+=val[s^1],Ln+=x;
			if( t&1) ans+=val[t^1],Rn+=x; 
		}
		for(;s;s>>=1,t>>=1){
			ans+=tag[s]*Ln;
			ans+=tag[t]*Rn;
		}
		return ans;
	}
}st;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	st.build(a,n);
	while(m--){
		scanf("%d%d%d",&t,&x,&y);
		if(t==2) printf("%lld\n",st.query(x,y));
		else{
			scanf("%d",&k);
			st.update(x,y,k);
		}
	}
}
