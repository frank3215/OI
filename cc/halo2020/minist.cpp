#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int n, m;
long long val[N];
int u[N], v[N], w[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", u+i, v+i, w+i);
		val[u[i]]-=w[i];
		val[v[i]]+=w[i];
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i)
		if (val[i] >= 0) ans += val[i];
	cout << ans << endl;
}

