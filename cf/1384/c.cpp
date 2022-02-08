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

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

const int MAXN = 1e5+10;

int n, cnt[26][26];
char a[MAXN], b[MAXN];

int fa[MAXN];
int find(int x) { return fa[x]==x?x:fa[x]=find(fa[x]); }

void solve() {
	sd(n);
	scanf("%s", a);
	scanf("%s", b);
	memset(cnt, 0, sizeof(cnt));
	FOR(i,0,26) fa[i] = i;
	int ans = 0;
	FOR(i,0,n) {
		a[i]-='a', b[i]-='a';
		if (a[i] > b[i]) {
			puts("-1");
			return;
		} else {
			if (find(a[i]) != find(b[i])) ans++, fa[find(a[i])] = find(b[i]);
		}
	}
	printf("%d\n", ans);
}

signed main() {
#ifndef ONLINE_JUDGE
	FIO("c");
#endif
	int t; sd(t);
	while (t--) solve();
}
