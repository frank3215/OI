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

const int MAXN = 3e5+10;
int n, k, l;
int d[MAXN];

int get(int t) {
	t %= (2*k);
	return t < k ? k-t : t-k;
}

bool get(int d, int &cl, int &cr) {
	if (d+k <= l) {
		cl = 0, cr = 2*k-1;
		return true;
	}
	if (d > l) return false;
	cl++;
	if (cr != 2*k-1) cr++;
	if (d+get(cl) > l) {
		if (cl >= k) {
			return false;
		} else {
			cl = d+k-l;
		}
	}
	if (d+get(cr) > l) {
		if (cr <= k) {
			return false;
		} else {
			cr = l+k-d;
		}
	}
	return true;
}

void solve() {
	sd(n), sd(k), sd(l);
	FOR(i,1,n+1) sd(d[i]);
	int l = 0, r = 2*k;
	FOR(i,1,n+1) {
		if (!get(d[i], l, r)) {
			puts("No");
			return;
		}
		//printf("%d %d %d\n", i, l, r);
	}
	puts("Yes");
}

signed main() {
#ifndef ONLINE_JUDGE
	FIO("b2");
#endif
	int t; sd(t);
	while (t--) solve();
}
