#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 4e7+10, maxm = 1e5+10;
int n, type;
int x, y, z, m;
int p[maxm], l[maxm], r[maxm];

ll a[maxn]; int g[maxn];
int id[maxn], qb, qe;

#define f(i) (a[i]-a[g[i]])
#define q(i) (a[id[i]]+f(id[i]))

void pr(__int128 x) {
	if (x) {
		pr(x/10);
		printf("%d", (int)(x%10));
	}
}

void solve() {
	for (int i = 1; i <= n; ++i) {
		a[i] = a[i-1]+a[i];
	}
	a[0] = 0, g[0] = 0;
	id[qe] = 0;
	int cur = 0;
	for (int i = 1; i <= n; ++i) {
		while (cur != qe && q(cur+1) <= a[i]) ++cur;
		g[i] = id[cur];
		while (qe >= qb && q(qe) >= a[i]+f(i)) {
			id[qe--] = 0;
		}
		id[++qe] = i;
	}
	__int128 ans = 0;
	for (int i = n; i != 0; i = g[i]) {
		ans += (__int128)f(i)*f(i);
	}
	pr(ans);
}

int main() {
//	freopen("partition.in", "r", stdin);
//	freopen("partition.out", "w", stdout);
	scanf("%d%d", &n, &type);
	if (type == 0) {
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", a+i);
		}
	} else {
		scanf("%d%d%d%lld%lld%d", &x, &y, &z, a+1, a+2, &m);
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d%d", p+i, l+i, r+i);
		}
		for (int i = 3; i <= n; ++i) {
			a[i] = (x*a[i-1] + y*a[i-2] + z) % (1<<30);
		}
		for (int i = 1; i <= m; ++i) {
			for (int j = p[i-1]+1; j <= p[i]; ++j)
				a[j] = a[j]%(r[i]-l[i]+1)+l[i];
		}
	}
	solve();
}
