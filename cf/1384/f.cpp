#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sd(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(x) scanf("%s", x)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define debug(x) cout << #x << " = " << x << endl
#define FIO(x) \
	freopen(x ".in", "r", stdin); \
	freopen(x ".out", "w", stdout);
#define ddebug(a,n) cout << #a << " = ";print(a,n)
#define print(a,n) FOR(_,0,n) printf("%d%c", a, " \n"[_==n-1])
void _print(int *a, int n) { }
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

const int N = 300;

int n, m;
int a[N][N], h[N], v[N];
int ans[N][N];

signed main() {
#ifndef ONLINE_JUDGE
	FIO("a");
#endif
	sd(n), sd(m);
	FOR(i,0,n) FOR(j,0,m) {
		sd(a[i][j]);
		h[i] = max(h[i], a[i][j]);
		v[j] = max(v[j], a[i][j]);
	}
	sort(h, h+n, greater<int>());
	sort(v, v+m, greater<int>());
	int ph = 0, pv = 0;
	queue<pii> q;
	ROF(i,1,n*m+1) {
		if (ph < n && i == h[ph+1]) ph++;
		if (pv < m && i == v[pv+1]) pv++;
		if (i == h[ph] || i == v[pv]) {
			ans[ph][pv] = i;
			if (i == h[ph]) ROF(i,0,pv) q.push(mp(ph,i));
			if (i == v[pv]) ROF(i,0,ph) q.push(mp(i,pv));
		} else {
			pii p = q.front(); q.pop();
			ans[p.fi][p.se] = i;
		}
	}
	FOR(i,0,n) { print(ans[i][_],m); }
}
