#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; --i)
#define debug(x) cout << #x << " = " << x << endl
#define FIO(x) \
	freopen(x ".in", "r", stdin); \
	freopen(x ".out", "w", stdout);
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

const int N=1<<21|1,mo=998244353;
inline int poww(int x,int y){int ans=1;for(;y;y>>=1,x=x*x%mo)if(y&1)ans=ans*x%mo;return ans;}
inline void red(int&x){x+=x>>31&mo;}
struct NTT{
	int b[N],wn[N],l,invl;
	inline void ini(int n){
		invl=poww(l=n,mo-2);int i;
		for(i=1;i<l;++i)b[i]=b[i>>1]>>1|(i&1?l>>1:0);
		for(i=2,wn[*wn=1]=poww(3,(mo-1)/l);i<=l;++i)wn[i]=wn[1]*wn[i-1]%mo;
	}
	inline void DFT(int*a,int key){
		static int w[N];int i,j,k,m,u;
		for(i=0;i<l;++i)if(i<b[i])swap(a[i],a[b[i]]);
		for(i=2;i<=l;i<<=1){
			for(m=i>>1,j=k=0;k<m;++k,j+=l/i)w[k]=wn[j];
			for(j=0;j<l;j+=i)for(k=0;k<m;++k)u=w[k]*a[j+k+m]%mo,
				red(a[j+k+m]=a[j+k]-u),red(a[j+k]+=u-mo);
		}
		if(key==-1)for(i=0,std::reverse(a+1,a+l);i<l;++i)a[i]=a[i]*invl%mo;
	}
}F;

int n,m,a[N],b[N];

signed main() {
#ifndef ONLINE_JUDGE
	FIO("c");
#endif
	scanf("%d%d",&n,&m);
	FOR(i,0,n+1)scanf("%d",a+i);
	FOR(i,0,m+1)scanf("%d",b+i);
	int l=1;while(l<=n+m+1) l<<=1;
	F.ini(l);
	F.DFT(a,1);F.DFT(b,1);
	FOR(i,0,l)a[i]=a[i]*b[i]%mo;
	F.DFT(a,-1);
	FOR(i,0,n+m+1)printf("%d ",a[i]);
}

