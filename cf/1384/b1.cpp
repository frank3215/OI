#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sd(x) scanf("%lld", &x)
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; --i)
#define debug(x) cout << #x << " = " << x << endl
#define FIO(x) \
	freopen(x ".in", "r", stdin); \
	freopen(x ".out", "w", stdout);
#define print(a,n) cout << #a << " = ";_print(a,n);
void _print(int *a, int n) { FOR(i,0,n) printf("%lld%c", a[i], " \n"[i==n-1]); }
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

const int MAXN = 110, MAXT = 2e4+10;
int n, k, l;
int d[MAXN];
bool ok[MAXN][MAXT];

int get(int t) {
	t %= 2*k;
	return t < k ? t : 2*k-t;
}

void solve() {
	sd(n), sd(k), sd(l);
	FOR(i,1,n+1) sd(d[i]);
	memset(ok, 1, 2*n*k+1);
	FOR(i,1,n+1) {
		FOR(j,1,2*n*k+1) {
			ok[i][j] = ((ok[i-1][j-1] || ok[i][j-1]) && d[i]+get(j) <= l);
		}
	}
	FOR(j,1,2*n*k+1) if (ok[n][j]) { puts("Yes"); return; }
	puts("No");
}

signed main() {
#ifndef ONLINE_JUDGE
	FIO("b1");
#endif
	int t; sd(t);
	while (t--) solve();
}
