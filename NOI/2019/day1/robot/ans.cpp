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

int& red(int &x) { return x+=x>>31&P; }
int add(int x, int y) { return x+y>=P?x+y-P:x+y; }
int& Add(int &x, int y) { return red(x += y-P); }
int sub(int x, int y) { return x-y<0?x-y+P:x-y; }
int& Sub(int &x, int y) { return red(x -= y); }
int mul(int x, int y) { return x*y%P; }
int& Mul(int &x, int y) { return x = mul(x,y); }

int inv[MAXN];
void init() {
	inv[1] = 1;
	FOR(i,2,MAXN) {
		inv[i] = P-(P/i)*inv[P%i]%P;
	}
}

struct Poly{
	int n;
	vector<int> a;
	Poly(int _n = 1): n(_n), a(_n) {}
	int size() { return n; }
	int& operator [](const int &x) { return a[x]; }
	const int& operator [](const int &x) const { return a[x]; }
	int operator ()(const int &x) {
		int ret = 0, cur = 1;
		FOR(i,0,n) {
			Add(ret, mul(cur, a[i]));
			Mul(cur, x-i);
		}
		return ret;
	}
	Poly operator +(const Poly &y) const {
		Poly ret(max(n,y.n));
		FOR(i,0,n) Add(ret[i], a[i]);
		FOR(j,0,y.n) Add(ret[j], y[j]);
		return ret;
	}
	Poly operator *(Poly x) const {
		Poly ret(x.n+n-1);
		FOR(i,0,n) {
			FOR(j,0,x.n) Add(ret[i+j], mul(x[j], a[i]));
			FOR(j,1,x.n) Add(x[j-1], mul(j, x[j]));
		}
		return ret;
	}
	Poly inter() const {
		Poly r(n+1);
		ROF(i,1,n+1) r.a[i] = mul(a[i-1], inv[i]);
		r.a[0] = 0;
		return r;
	}
};

struct state{
	vector<int> x;
	vector<Poly> p;
	state inter() {
		state r;
		FOR(i,0,(int)p.size()) {
			r.p.pb(p[i].inter());
			r.x.pb(x[i]);
			if (i)
				r.p[i][0] = (r.p[i][0] + r.p[i-1](x[i]) - r.p[i](x[i]) + P)%P;
		}
		return r;
	}
	state op(state y, int op) const {
		state ret;
		int li = 0, ri = 0, pos = 0, sx = x.size(), sy = y.x.size();
		while (li < (int)x.size() && ri < (int)y.x.size()) {
			ret.p.pb(op ? p[li]*y.p[ri] : p[li]+y.p[ri]);
			ret.x.pb(pos);
			if (li == sx-1 && ri == sy-1) break;
			if (ri == sy-1 || li != sx-1 && x[li+1] <= y.x[ri+1]) {
				pos = x[++li];
			} else {
				pos = y.x[++ri];
			}
			while (li+1 < sx && x[li+1] <= pos) ++li;
			while (ri+1 < sy && y.x[ri+1] <= pos) ++ri;
		}
		return ret;
	}
	state lim(int a, int b) const {
		state r;
		r.p.pb(Poly(1)); r.x.pb(0);
		FOR(i,0,(int)p.size()) {
			if (x[i] <= b && (i+1 == (int)p.size() || x[i+1] > a)) {
				r.p.pb(p[i]);
				r.x.pb(max(a,x[i]));
			}
		}
		r.p.pb(Poly(1)); r.x.pb(b+1);
		return r;
	}
}dp[MAXS];

void solve(int l, int r) {
	if (id[l][r]) return;
	if (l > r) return;
	int cur = id[l][r] = ++tot;
	dp[cur].p.pb(Poly(1));
	dp[cur].x.pb(0);
	FOR(i,l,r+1) if (abs((r-i)-(i-l)) <= 2) {
		solve(l,i-1);
		solve(i+1, r);
		state A = dp[id[l][i-1]], B = dp[id[i+1][r]];
		if (l<i) A = A.op(A.inter(),0);
		if (i<r) B = B.inter();
		dp[cur] = dp[cur].op(A.op(B,1).lim(a[i],b[i]),0);
	}
}

signed main() {
	init();
#ifndef ONLINE_JUDGE
	freopen("robot.in", "r", stdin);
	freopen("robot.out", "w", stdout);
#endif
	scanf("%lld", &n);
	FOR(i,1,n+1) scanf("%lld%lld", a+i, b+i);
	dp[0].p.pb(Poly(1));
	dp[0].p[0][0] = 1;
	dp[0].x.pb(0);
	solve(1, n);
	printf("%lld\n", dp[id[1][n]].inter().p.back()[0]);
}
