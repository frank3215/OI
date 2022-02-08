#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sd(x) scanf("%d", &x)
#define ss(x) scanf("%s", x)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define debug(x) cout << #x << " = " << x << endl
#define FIO(x) \
	freopen(x ".in", "r", stdin); \
	freopen(x ".out", "w", stdout);
#define print(a,n) cout << #a << " = ";FOR(_,0,n) printf("%d%c", a, " \n"[i==n-1])
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

const int N = 20, M = 1e5+10;

int fa[N];
int find(int x) { return fa[x]==x?x:fa[x]=find(fa[x]); }

int n, to[N];
char a[M], b[M];
bool dp[1<<N];

void solve() {
	sd(n);ss(a);ss(b);
	memset(to, 0, sizeof(to));
	int cc = 20;
	FOR(i,0,20) fa[i] = i;
	FOR(i,0,n) {
		int x = a[i]-'a', y = b[i]-'a';
		if (x != y) {
			to[x] |= 1<<y;
			cc -= find(x) != find(y);
			fa[find(x)] = find(y);
		}
	}
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	int ans = 0;
	FOR(i,0,1<<20) if (dp[i]) {
		int cnt = 0;
		FOR(j,0,20) {
			if (i >> j & 1) {
				cnt++;
			} else if ((to[j]&i) == 0) {
				dp[i|(1<<j)] = 1;
			}
		}
		ans = max(ans, cnt);
	}
	ans = 20+(20-ans)-cc;
	printf("%d\n", ans);
}

signed main() {
#ifndef ONLINE_JUDGE
	FIO("a");
#endif
	int t;
	sd(t);
	while (t--) solve();
}
