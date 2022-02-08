#include <bits/stdc++.h>

#define C ans.first
#define J ans.second
#define debug //

using namespace std;

const int maxn = 100+10, maxc = 200+10, inf = 1e9;

int n;
bool flag;
int c[maxn], p[maxn];
pair<int, int> ans;

int mx, mn, tmp;

void clean() {
	flag = 0;
	ans = make_pair(0, 0);
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", c+i, p+i);
		if (i && c[i] <= c[i-1] && p[i] <= p[i-1]) flag = 1;
	}
	if (flag) {
		puts("IMPOSSIBLE");
		return;
	}
	for (C = 1; C < maxc; ++C) {
		mn = 0, mx = inf;
		debug("C: %d\n", C);
		for (int i = 1; i < n; ++i) {
			int dc = abs(c[i]-c[i-1]), dp = abs(p[i]-p[i-1]);
			debug("d: %d %d\n", (c[i]-c[i-1]), (p[i]-p[i-1]));
			if (c[i] >= c[i-1] && p[i] >= p[i-1]) continue;
			else if (c[i] > c[i-1] && p[i] < p[i-1]) {
				tmp = (dc*C-1)/dp;
				debug("mx: %d\n", tmp);
				mx = min(mx, tmp);
			}
			else if (c[i] < c[i-1] && p[i] > p[i-1]) {
				tmp = (dc*C)/dp+1;
				debug("mn: %d\n", tmp);
				mn = max(mn, tmp);
			}
			else assert(0);
		}
		debug("%d %d\n", mn, mx);
		if (mn == inf) mn = 1;
		if (mx >= mn && mx >= 1) {
			J = max(1, mn);
			printf("%d %d\n", C, J);
			return;
		}
	}
	if (C == maxc) puts("IMPOSSIBLE");
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		printf("Case #%d: ", i);
		clean();
		solve();
	}
}

