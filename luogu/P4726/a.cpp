#include <bits/stdc++.h>
//#define int long long
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

const int L = 18, N = 1<<L|1, P = 998244353;

int poww(int a,int x=P-2){int ans=1;for(;x;a=(ll)a*a%P,x>>=1)if(x&1)ans=1ll*ans*a%P;return ans;}
void red(int&x){x+=x>>31&P;}
int mul(int x,int y){return (ll)x*y%P;}

int lo[N],inv[N];
struct NTT{
	int r[N],wn[N],l,invl;
	void ini(int n){
		invl=poww(l=n);FOR(i,1,l)r[i]=r[i>>1]>>1|(i&1?l>>1:0);
		wn[*wn=1]=poww(3,(P-1)/l);FOR(i,2,l/2)wn[i]=1ll*wn[i-1]*wn[1]%P;
	}
	void DFT(int*a,int key){
		static int w[N];int i,j,k,m,u;
		FOR(i,0,l)if(i<r[i])swap(a[i],a[r[i]]);
		for(i=2;i<=l;i<<=1){
			for(m=i>>1,j=k=0;k<m;++k,j+=l/i)w[k]=wn[j];
			for(j=0;j<l;j+=i)for(k=0;k<m;++k)u=1ll*a[j+k+m]*w[k]%P,
				red(a[j+k+m]=a[j+k]-u), red(a[j+k]+=u-P);
		}
		if(key==-1){for(i=0,reverse(a+1,a+l);i<l;++i)a[i]=1ll*a[i]*invl%P;}
	}
}F[L+1];

void Int(int*a,int*b,int n){ FOR(i,1,n)b[i]=1ll*inv[i]*a[i-1]%P; b[0]=0; }
void Dir(int*a,int*b,int n){ ROF(i,1,n)b[i-1]=1ll*i*a[i]%P; b[n-1]=0; }

void get_inv(int*a,int*b,int n){
	if(n==1){assert(a[0]);b[0]=poww(a[0]);return;}
	get_inv(a,b,(n+1)/2);
	static int c[N],d[N];int z=lo[2*n],l=1<<z;
	FOR(i,0,n)c[i]=a[i],d[i]=b[i];
	F[z].DFT(c,1), F[z].DFT(d,1);
	FOR(i,0,l)c[i]=mul(c[i],mul(d[i],d[i]));
	F[z].DFT(c,-1);
	FOR(i,0,n)red(b[i]+=b[i]-P),red(b[i]-=c[i]);
	FOR(i,0,l)c[i]=d[i]=0;
}

void get_ln(int*a,int*b,int n) {
	static int c[N],d[N];int z=lo[2*n],l=1<<z;
	Dir(a,c,n); get_inv(a,d,n);
	F[z].DFT(d,1); F[z].DFT(c,1);
	FOR(i,0,l)c[i]=mul(c[i],d[i]);
	F[z].DFT(c,-1); Int(c,b,n);
	FOR(i,0,l) c[i]=d[i]=0;
}

void get_exp(int*a,int*b,int n) {
	if(n==1){ assert(a[0]==0); b[0]=1; return; }
	get_exp(a,b,(n+1)/2);
	static int d[N];int z=lo[2*n],l=1<<z;
	get_ln(b,d,n);
	red(d[0]=a[0]+1-d[0]); FOR(i,1,n) red(d[i]=a[i]-d[i]);
	F[z].DFT(d,1), F[z].DFT(b,1);
	FOR(i,0,l)b[i]=mul(b[i],d[i]);
	F[z].DFT(b,-1);
	FOR(i,n,l)b[i]=0;
	FOR(i,0,l)d[i]=0;
}

int n, a[N], b[N];

signed main() {
	FOR(i,0,L+1)F[i].ini(1<<i);
	inv[1]=1; FOR(i,2,N)inv[i]=P-1ll*inv[P%i]*(P/i)%P;
	FOR(i,2,N)lo[i]=lo[i-1]+((1<<lo[i-1])<i);
#ifndef ONLINE_JUDGE
	FIO("a");
#endif
	scanf("%d", &n);
	FOR(i,0,n)scanf("%d",a+i);
	get_exp(a,b,n);
	FOR(i,0,n)printf("%d ",b[i]);
}
