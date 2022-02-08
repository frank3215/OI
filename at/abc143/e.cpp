#include <bits/stdc++.h>
#define F(i) for (int i = 1; i <= n; ++i)
using namespace std;

const int maxn = 300+10, maxlogn = 10, inf = 0x3f3f3f3f;

int n, m, l, q;
int g[maxn][maxn], f[maxn][maxn];

void floyd(int d[maxn][maxn]) { F(k) F(i) F(j) d[i][j] = min(d[i][j], d[i][k]+d[k][j]); }

int main() {
	int a, b, c;
	cin >> n >> m >> l;
	memset(g, 0x3f, sizeof(g));
	for (int i = 1; i <= m; ++i) {
		cin >> a >> b >> c;
		g[a][b] = g[b][a] = c;
	}
	floyd(g);
	memset(f, 0x3f, sizeof(f));
	F(i) F(j) if (g[i][j] <= l) f[i][j] = 1;
	floyd(f);
	cin >> q;
	while (q--) {
		cin >> a >> b;
		cout << (f[a][b]==inf?-1:f[a][b]-1) << endl;
	}
}
