#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; --i)
using namespace std;

const int MAXN = 310, MAXH = 1e9+1e8, P = 1e9+7, MAXS = 2300;

int n, a[MAXN], b[MAXN];
int id[MAXN][MAXN], tot;

struct Poly{
	int n;
	vector<int> a;
};
struct state{
	int l, r;
	Poly p;
};
vector<state> dp[MAXS];

int da[MAXN][MAXN], db[MAXN][MAXN], tmp[MAXN];
int inv[MAXN];
void init() {
	da[0][0] = 1;
	FOR(i,0,MAXN-1) {
		FOR(j,0,i+1) {
			(da[i+1][j+1] += da[i][j]) %= P;
			(da[i+1][j] += da[i][j]*i) %= P;
		}
	}
	FOR(i,0,MAXN) {
		tmp[i] = 1;
		ROF(j,0,i+1) {
			db[i][j] = tmp[j];
			FOR(k,0,j+1) {
				tmp[k] = (tmp[k]-db[i][j]*da[j][k])%P;
			}
		}
	}
	//puts("!");
	inv[1] = 1;
	FOR(i,2,MAXN) {
		inv[i] = P-(P/i)*inv[P%i]%P;
		//printf("inv[%lld] = %lld\n", i, inv[i]);
	}
}

Poly Add(const Poly &x, const Poly &y) {
	Poly ret;
	ret.n = max(x.n,y.n);
	ret.a.resize(ret.n+1);
	FOR(i,0,x.n+1) {
		(ret.a[i] += x.a[i]) %= P;
	}
	FOR(j,0,y.n+1) {
		(ret.a[j] += y.a[j]) %= P;
	}
	return ret;
}
Poly Mult(const Poly &x, const Poly &y) {
	Poly ret;
	ret.n = x.n+y.n;
	ret.a.resize(ret.n+1);
	FOR(i,0,x.n+1) {
		FOR(j,0,y.n+1) {
			(ret.a[i+j] += x.a[i]*y.a[j]) %= P;
		}
	}
	return ret;
}
Poly TransSigma(const Poly &p) {
	Poly ret;
	ret.n = p.n+1;
	ret.a.resize(ret.n+1);
	FOR(i,0,p.n+1) {
		FOR(j,0,i+1) {
			(ret.a[j+1] += da[i][j]*p.a[i]%P*inv[p.n+1]) %= P;
		}
	}
	return ret;
}
Poly Rev(const Poly &p) {
	Poly ret;
	ret.n = p.n;
	ret.a.resize(ret.n+1);
	FOR(i,0,p.n+1) {
		FOR(j,0,i+1) {
			(ret.a[j] += db[i][j]*p.a[i]) %= P;
		}
	}
	return ret;
}
int Get(const Poly &p, int x) {
	int ret = 0;
	ROF(i,p.n+1,0) {
		ret = (ret*x + p.a[i])%P;
	}
	return ret;
}

void print(vector<state> v) {
	FOR(i,0,(int)v.size()) {
		printf("\t%d %d %d: {", v[i].l, v[i].r, v[i].p.n);
		ROF(j,0,v[i].p.n+1) printf(" %d", v[i].p.a[j]);
		printf("\n");
	}
}

vector<state> Mult(const vector<state> x, const vector<state> y) {
	vector<state> ret;
	int li = 0, ri = 0, l = 0;
	while (li < (int)x.size() && ri < (int)y.size()) {
		int r = min(x[li].r, y[ri].r==MAXH-1?MAXH-1:y[ri].r);
		ret.pb((state){l,r,Mult(x[li].p, y[ri].p)});
		l = r+1;
		while (li < (int)x.size() && x[li].r < l) ++li;
		while (ri < (int)y.size() && y[ri].r-1 < l) ++ri;
	}
	printf("Mult([%d,%d]\n", L, R);
	print(x);
	printf("\t,\n");
	print(y);
	printf(") = \n");
	print(ret);
	return ret;
}

vector<state> Add(const vector<state> x, const vector<state> y) {
	if (!x.size()) return y;
	vector<state> ret;
	int li = 0, ri = 0, l = 0;
	while (li < (int)x.size() && ri < (int)y.size()) {
		int r = min(x[li].r, y[ri].r);
		ret.pb((state){l,r,Add(x[li].p, y[ri].p)});
		l = r+1;
		while (li < (int)x.size() && x[li].r < l) ++li;
		while (ri < (int)y.size() && y[ri].r < l) ++ri;
	}
	return ret;
}

void solve(int l, int r);
void _solve(int l, int r) {
	if (l > r) return;
	if (id[l][r]) return;
	int cur = id[l][r] = ++tot;
	if (l == r) {
		dp[cur].push_back((state){0,a[l]-1,(Poly){0,{0}}});
		dp[cur].push_back((state){a[l],b[l],(Poly){1,{1-a[l], 1}}});
		dp[cur].push_back((state){b[l]+1,MAXH-1,(Poly){0, {b[l]-a[l]+1}}});
		return;
	} else {
		int mmid = (l+r)>>1;
		vector<int> tmp;
		FOR(mid,mmid-(r-l+1)%2,mmid+2) {
			solve(l,mid-1);
			solve(mid+1, r);
			solve(mid, mid);
			dp[cur] = Add(dp[cur], Mult(dp[id[mid][mid]], Mult(dp[id[l][mid-1]], dp[id[mid+1][r]])));
		}
	}
	// Prefix Sum
	FOR(i,1,(int)dp[cur].size()) {
		TransSigma(dp[cur][i].p);
		Rev(dp[cur][i].p);
		int x = Get(dp[cur][i].p, dp[cur][i].l-1), y = Get(dp[cur][i-1].p, dp[cur][i-1].r);
		(dp[cur][i].p.a[0] += y-x) %= P;
	}
}
void solve(int l, int r) {
	if (l > r || id[l][r]) return;
	//printf("solve(%d, %d) {\n", l, r);
	_solve(l, r);
	printf("solve(%d, %d) \n", l, r);
	print(dp[id[l][r]]);
}

signed main() {
	init();
#ifndef ONLINE_JUDGE
	freopen("robot.in", "r", stdin);
	freopen("robot.out", "w", stdout);
#endif
	scanf("%lld", &n);
	FOR(i,1,n+1) scanf("%lld%lld", a+i, b+i);
	dp[0].pb((state){0, MAXH-1, (Poly){0, {1}}});
	solve(1, n);
	printf("%lld\n", Get(dp[id[1][n]].back().p,MAXH-1));
}
