#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn = 18, max2n = 1<<maxn;

int n;
unsigned f[max2n];
bool g[max2n];
char G[maxn][maxn+1];

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%s", G[i]);
	for (int s = 0; s < 1<<n; ++s) {
		g[s] = 1;
		for (int i = 0; i < n; ++i) if (s>>i&1)
			for (int j = 0; j < n; ++j) if (s>>j&1)
				if (G[i][j] == '1') g[s] = 0;
		if (g[s]) f[s] = 1;
	}
	unsigned pow=1, ans = 0;
	for (int s = 1; s < 1<<n; ++s) {
		if (!g[s]) {
			f[s] = n+1;
			for (int ss = s; ss; ss = (ss-1)&s)
				if (g[ss]) f[s] = min(f[s^ss]+1, f[s]);
		}
		pow *= 233;
		ans += pow*f[s];
	}
	printf("%u\n", ans);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
}
