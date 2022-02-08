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

const int N = 1<<18|1, P = 998244353;

int qpow(int a,int x=P-2){int ret=1;for(;x;a=(ll)a*a%P,x>>=1)if(x&1)ret=(ll)ret*a%P;return ret;}
void red(int &x){x+=x>>31&P;}

int lo[N];
struct NTT{
	int r[N],wn[N],l,invl;
	void ini(int n){
		invl=qpow(l=n);int i;
		for(i=1;i<l;++i)r[i]=r[i>>1]>>1|(i&1?l>>1:0);
		for(i=2,wn[*wn=1]=qpow(3,(P-1)/l);i<=l;++i)wn[i]=(ll)wn[i-1]*wn[1]%P;
	}
	void DFT(int*a,int key){
		static int w[N];int i,j,k,m,u;
		for(i=0;i<l;++i)if(i<r[i])swap(a[i],a[r[i]]);
		for(i=2;i<=l;i<<=1){
			for(m=i>>1,j=k=0;k<m;++k,j+=l/i)w[k]=wn[j];
			for(j=0;j<l;j+=i)for(k=0;k<m;++k)u=(ll)w[k]*a[j+k+m]%P,
				red(a[j+k+m]=a[j+k]-u),red(a[j+k]+=u-P);
		}
		if(key==-1)for(i=0,reverse(a+1,a+l);i<l;++i)a[i]=(ll)a[i]*invl%P;
	}
}F[19];

int n;
int a[N],b[N];

void Inv(int*a,int*b,int n) {
	static int c[N],d[N];
	if(n==1){assert(a[0]);b[0]=qpow(a[0]);return;}
	Inv(a,b,(n+1)/2);
	int z=lo[2*n],l=1<<z;
	FOR(i,0,n)c[i]=a[i],d[i]=b[i];
	FOR(i,n,l)c[i]=d[i]=0; F[z].DFT(c,1),F[z].DFT(d,1);
	FOR(i,0,1<<z)c[i]=(ll)c[i]*d[i]%P*d[i]%P; F[z].DFT(c,-1);
	FOR(i,0,n)red(b[i]+=b[i]-P),red(b[i]-=c[i]);
}
void Diff(int*a,int n){ FOR(i,1,n)a[i-1]=(ll)a[i]*i%P; }
void Int(int*a,int n){ ROF(i,1,n)a[i]=(ll)a[i-1]*qpow(i)%P; a[0] = 0; }
void Get_ln(int*a,int*b,int n){
	int z=lo[2*n],l=1<<z;
	static int c[N],d[N];
	FOR(i,0,n) c[i]=a[i];
	FOR(i,n,l) c[i] = 0; Diff(c,l); Inv(a,d,n);
	FOR(i,n,l) d[i] = 0;
	F[z].DFT(c,1), F[z].DFT(d,1);
	FOR(i,0,l) c[i] = 1ll*c[i]*d[i]%P; F[z].DFT(c,-1); Int(c,l);
	FOR(i,0,n) b[i] = c[i];
}

signed main() {
	FOR(i,2,N) lo[i] = lo[i-1]+((1<<lo[i-1])<i);
	FOR(i,0,19) F[i].ini(1<<i);
#ifndef ONLINE_JUDGE
	FIO("a");
#endif
	scanf("%d", &n);
	FOR(i,0,n) scanf("%d", a+i);
	Get_ln(a,b,n);
	FOR(i,0,n) printf("%d ",b[i]);
}
