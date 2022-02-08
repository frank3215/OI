#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,b) FOR(i,0,b)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,b) ROF(i,0,b)

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define ITER(i,x) for (auto &i: x)
#define ITE(i,x) for (auto i: x)
#define IT(i,x) for (auto i = x.begin(); i != x.end(); ++i)
#define ALL(x) x.begin(), x.end()
#define P pair
#define V vector
#define I int
#define D(x) cerr << #x << " = " << x << endl;

//#define double long double
//#define int long long

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppp;

void solve() {
	int n, m;
	ll ans = 0;
	cin >> n >> m;
	V<V<I> > a(n,V<I>(m)), r(n,V<I>(m)), c(m,V<I>(n));
	F0R(i,n) F0R(j,m) cin >> a[i][j];
	F0R(i,n) {
		V<I> &v = r[i];
		int l = 0;
		F0R(j,m) {
			if (j <= l+v[l]) v[j] = min(v[2*l-j], l+v[l]-j);
			while (v[j] < j && j+v[j] < m-1 && a[i][j+v[j]+1] == a[i][j-v[j]-1]) ++v[j];
			if (j+v[j] > l+v[l]) l = j;
		}
	}
	F0R(j,m) {
		V<I> &v = c[j];
		int l = 0;
		F0R(i,n) {
			if (i <= l+v[l]) v[i] = min(v[2*l-i], l+v[l]-i);
			while (v[i] < i && i+v[i] < n-1 && a[i+v[i]+1][j] == a[i-v[i]-1][j]) ++v[i];
			if (i+v[i] > l+v[l]) l = i;
		}
	}
	F0R(i,n) F0R(j,m) ans += min(r[i][j],c[j][i])+1;
	cout << ans << endl;
}

signed main() {
	int t;
	cin >> t;
	while (t--) solve();
}
