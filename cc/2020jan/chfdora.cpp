#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define R1P(i,b) REP(i,1,b)

#define V vector
#define I int
#define D(x) cerr << #x << " = " << x << endl;

void solve() {
	int n, m, ans = 0;
	cin >> n >> m;
	V<V<I> > a(n+2,V<I>(m+2));
	R1P(i,n) R1P(j,m) cin >> a[i][j];
	R1P(i,n) {
		R1P(j,m) {
			for (int t = 0; a[i-t][j] && a[i][j-t] && a[i-t][j] == a[i+t][j] && a[i][j-t] == a[i][j+t]; ++t) ans++;
		}
	}
	cout << ans << endl;
}

signed main() {
	int t;
	cin >> t;
	while (t--) solve();
}
