#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define fi first
#define se second
#define mp make_pair
#define int long long

const int N = 31, numM = N*(N-1)/2, P = 998244353, MX = 152501;

typedef pair<int,int> pii;

int n, m;
int u[numM], v[numM], w[numM];
int ans;

namespace {
	int f[N];
	int find(int u) { return f[u]==u?u:f[u]=find(f[u]); }

	int qpow(int a, int x = P-2) {
		int ret = 1;
		for (; x; x >>= 1, a = a*a%P) if (x&1) ret = ret*a%P;
		return ret;
	}

	pii M[N][N];

	void add(pii &p, pii x) {
		p.fi = (p.fi+x.fi)%P;
		p.se = (p.se+x.se)%P;
	}
	void add(int u, int v, int w) {
		add(M[u][v], mp(-w,-1));
		add(M[v][u], mp(-w,-1));
		add(M[u][u], mp(w,1));
		add(M[v][v], mp(w,1));
	}

	pair<int,int> div(pii a, pii b) {
		if (!b.se) {
			//assert(!a.se);
			//assert(b.fi);
			return mp(0ll, a.fi*qpow(b.fi)%P);
		}
		pii ret;
		ret.se = a.se*qpow(b.se)%P;
		ret.fi = (a.fi-ret.se*b.fi)%P*qpow(b.se)%P;
		return ret;
	}
	pair<int,int> mul(pii a, pii b) {
		return mp((a.fi*b.se+a.se*b.fi)%P, a.se*b.se%P);
	}

	int matrix_tree() {
		int ret = 1;
		FOR(i,1,n) {
			FOR(j,i,n) if (M[i][j].se != 0) {
				if (i != j) swap(M[i], M[j]), ret = -ret;
				break;
			}
			if (!M[i][i].fi) {
				FOR(j,i,n) if (M[i][j].se != 0) {
					if (i != j) swap(M[i], M[j]), ret = -ret;
					break;
				}
				if (!M[i][i].se) return 0;
			}
			FOR(j,1,n) if (j != i) {
				pair<int,int> mult = div(M[j][i], M[i][i]);
				mult.fi = -mult.fi;
				mult.se = -mult.se;
				FOR(k,1,n) {
					add(M[j][k], mul(mult,M[i][k]));
				}
			}
		}
		pair<int,int> Ret = mp(0,ret);
		FOR(i,1,n) Ret = mul(Ret, M[i][i]);
		return Ret.fi;
	}

	int nop[MX+1], prime[MX+1], d[MX+1], phi[MX+1], pt;

	void solve() {
		phi[1] = 1;
		FOR(i,2,MX+1) {
			if (!nop[i]) prime[pt++] = i, d[i] = i, phi[i] = i-1;
			FOR(j,0,pt) {
				if (i*prime[j] > MX || prime[j] > d[i]) break;
				//printf(" %lld %lld\n", prime[j], d[i]);
				int k = i*prime[j];
				nop[k] = 1;
				d[k] = min(d[i], prime[j]);
				if (d[k] != d[i]) phi[k] = phi[i]*(d[k]-1);
				else phi[k] = phi[i]*d[k];
			}
			//if (i <= 100) printf("%lld %lld\n", i, phi[i]);
		}
		FOR(k,1,MX+1) {
			int cnt = 0;
			FOR(i,0,m) if (w[i]%k == 0) cnt++;
			if (cnt < n-1) continue;

			FOR(i,1,n+1) f[i] = i;
			FOR(i,0,m) if (w[i]%k == 0) {
				f[find(u[i])] = find(v[i]);
			}
			bool flag = true;
			FOR(i,1,n+1) if (find(i) != find(1)) { flag = false; break; }
			if (!flag) continue;
			memset(M, 0, sizeof(M));
			FOR(i,0,m) {
				if (w[i]%k == 0) {
					add(u[i]-1, v[i]-1, w[i]);
				}
			}
			ans = (ans + phi[k]*matrix_tree())%P;
			//printf("%lld %lld\n", k, (ans+P)%P);
		}
	}
}

namespace brute{
	int f[N];
	int find(int u) { return f[u]==u?u:f[u]=find(f[u]); }
	bool link(int u, int v) {
		int fu = find(u), fv = find(v);
		if (fu == fv) return false;
		f[fu] = fv;
		return true;
	}

	int gcd(int x, int y) { return y?gcd(y,x%y):x; }

	int e[numM];
	void dfs(int d, int k) {
		if (k > n-1 || k+(m-d) < n-1) return;
		if (d == m && k == n-1) {
			FOR(i,1,n+1) f[i] = i;
			int g = w[e[0]], sum = 0;
			FOR(_,0,n-1) {
				int i = e[_];
				if (!link(u[i], v[i])) return;
				g = gcd(g, w[i]);
				sum += w[i];
			}
			ans = (ans+sum*g)%P;
			return;
		}
		dfs(d+1, k);
		e[k] = d;
		dfs(d+1, k+1);
	}
}

signed main() {
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	FOR(i,0,m) {
		scanf("%lld%lld%lld", u+i, v+i, w+i);
	}
	if (m <= 15 || m <= n) brute::dfs(0,0);
	else solve();
	printf("%lld\n", (ans%P+P)%P);
}

