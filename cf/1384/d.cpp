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

int a[MAXN], cnt[2];

void solve() {
	int n; sd(n);
	FOR(i,0,n) sd(a[i]);
	ROF(k,0,30) {
		cnt[0] = cnt[1] = 0;
		FOR(i,0,n) cnt[a[i]>>k&1]++;
		if (cnt[1]%2 == 1) {
			if (cnt[1]%4 == 1) puts("WIN");
			else if (cnt[0]%2 == 1) puts("WIN");
			else puts("LOSE");
			return;
		}
	}
	puts("DRAW");
}

signed main() {
#ifndef ONLINE_JUDGE
	FIO("a");
#endif
	int t; sd(t);
	while (t--) solve();
}

