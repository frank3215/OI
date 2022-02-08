#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;

int n, m, a[maxn], b[maxn], p[maxn];
vector<int> to[maxn];

bool cmd(int i, int j) { return a[i]-b[i] < a[j]-b[j]; }

int f[maxn];
long long B[maxn], w[maxn];
int find(int x) { return f[x]>0?f[x]=find(f[x]):x; }

bool vis[maxn];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", a+i, b+i);
		B[i] = b[i];
		p[i] = i;
	}
	int u, v;
	for (int j = 1; j <= m; ++j) {
		scanf("%d%d", &u, &v);
		to[u].push_back(v);
		to[v].push_back(u);
	}
	sort(p+1, p+1+n, cmd);
	for (int _ = 1; _ <= n; ++_) {
		int i = p[_];
//		printf("%d: %d\n", i, a[i]-b[i]);
		w[i] = max(0, a[i]-b[i]);
		for (auto __: to[i]) if (vis[__]) {
			int j = find(__);
			if (j == i) continue;
			if (B[j]+w[j] >= a[i]-b[i]) w[i] = min(w[i], w[j]);
			else w[i] = min(w[i], (a[i]-b[i])-B[j]);
			B[i] += B[j];
			f[j] = i;
		}
		vis[i] = 1;
//		printf("%d: B=%d w=%d\n", i, B[i], w[i]);
	}
	cout << w[p[n]]+B[p[n]] << endl;
}
