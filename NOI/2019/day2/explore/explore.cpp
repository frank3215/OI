#include "explore.h"
#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sd(x) scanf("%d", &x)
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; --i)
#define debug(x) cout << #x << " = " << x << endl
#define FIO(x) \
	freopen(x ".in", "r", stdin); \
	freopen(x ".out", "w", stdout);
#define print(a,n) cout << #a << " = ";_print(a,n);
void _print(int *a, int n) { FOR(i,0,n) printf("%d%c", a[i], " \n"[i==n-1]); }
using namespace std;

void modify(int x);
int query(int x);
void report(int x, int y);
int check(int x);

namespace solve_1_5{
	const int MAXN = 510;
	int cur[MAXN];
	void solve(int n, int m) {
		FOR(i,0,n-1) {
			cur[i] ^= 1;
			modify(i);
			FOR(j,i+1,n) {
				int tmp = query(j);
				if (tmp^cur[j]) report(i, j);
				cur[j] = tmp;
			}
		}
	}
}
namespace solve_a{
	const int MAXN = 2e5+10;
	int pre[MAXN], sum[MAXN];
	void solve(int n, int m) {
		int L = 1; while (1<<L < n) L++;
		FOR(i,0,L) {
			FOR(j,0,n) if (j>>i&1) {
				modify(j);
				pre[j] ^= 1;
			}
			FOR(j,0,n) {
				int tmp = query(j);
				if (tmp^pre[j]) sum[j] ^= 1<<i;
				pre[j] = tmp;
			}
		}
		FOR(i,0,n) if (sum[i] > i) {
			report(i, sum[i]);
		}
	}
}

namespace solve_b{
	const int MAXN = 2e5+10;
	int ans[MAXN];
	void work(vector<int> &q, int l, int r) {
		if (q.empty()) return;
		if (l == r) {
			for (auto u: q) report(u, l);
			return;
		}
		int mid = l+r>>1;
		FOR(i,l,mid+1) modify(i);
		vector<int> ql, qr;
		for (auto u: q) {
			if (u <= mid+1) ql.pb(u);
			else if (query(u)) ql.pb(u);
			else qr.pb(u);
		}
		FOR(i,l,mid+1) modify(i);
		work(ql, l, mid);
		work(qr, mid+1, r);
	}
	void solve(int n, int m) {
		vector<int> q;
		FOR(i,1,n) q.pb(i);
		work(q, 0, n-2);
	}
}

namespace solve{
	const int MAXN = 2e5+10;
	int ans[MAXN], p[MAXN], id[MAXN], vis[MAXN];
	int sum[MAXN];
	vector<int> adj[MAXN];
	void work(vector<int> &q, int l, int r) {
		if (q.empty()) return;
//		printf("work({");
//		for (auto i: q) printf("%d,", i);
//		printf("},%d,%d)\n", l, r); fflush(stdout);
		if (l == r) {
			for (auto i: q) if (i != l) {
//				cout << p[i] << ' ' << p[l] << endl;
				adj[p[i]].pb(p[l]);
				adj[p[l]].pb(p[i]);
				report(p[i], p[l]);
				vis[p[i]] = check(p[i]);
				vis[p[l]] = check(p[l]);
			}
			return;
		}
		int mid = l+r>>1;
		FOR(i,l,mid+1) {
			modify(p[i]);
			for (auto v: adj[p[i]]) sum[v] ^= 1;
		}
		vector<int> ql, qr;
		for (auto i: q) {
			if (i <= mid) ql.pb(i);
			else if (sum[p[i]]^query(p[i])) ql.pb(i);
			else qr.pb(i);
		}
		FOR(i,l,mid+1) {
			modify(p[i]);
			for (auto v: adj[p[i]]) sum[v] ^= 1;
		}
		work(ql, l, mid);
		work(qr, mid+1, r);
	}
	int tmp[MAXN];
	void solve(int N, int M) {
		vector<int> q;
		int n = N;
		FOR(i,0,n) p[i] = i;
		while (1) {
			int nn = 0;
			random_shuffle(p, p+n);
			FOR(i,0,n) if (!vis[p[i]]) tmp[nn++] = p[i];
			n = nn;
			if (!n) break;
			FOR(i,0,n) p[i] = tmp[i];
//			debug(n); print(p,n);
			FOR(i,0,n) id[i] = i;
			q.clear();
			FOR(i,0,n) q.pb(i);
			work(q, 0, n-1);
		}
	}
}

void explore(int N, int M) {
	if (N <= 500) solve_1_5::solve(N, M);
	else if (N%10 == 8) solve_a::solve(N, M);
	else if (N%10 == 7) solve_b::solve(N, M);
	else solve::solve(N, M);
}
