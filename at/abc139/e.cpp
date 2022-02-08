#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;

int n, a[maxn][maxn], p[maxn], t[maxn], ans, v[maxn];
queue<int> q, nq;

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < n; ++j)
			cin >> a[i][j];
		q.push(i);
		v[i] = 1;
	}
	for (ans = -1; !q.empty(); ans++) {
		nq = q;
		while (!q.empty()) {
			int i = q.front(); q.pop();
			t[i] = a[i][++p[i]];
			v[i] = 0;
		}
		while (!nq.empty()) {
			int i = nq.front(); nq.pop();
//			printf("%d ", i);
			if (!v[i] && t[t[i]] == i) {
				q.push(i);
				q.push(t[i]);
				v[i] = v[t[i]] = 1;
//				printf("(%d, %d) ", i, t[i]);
			}
		}
//		putchar('\n');
	}
	for (int i = 1; i <= n; ++i)
		if (p[i] != n)
			ans = -1;
	printf("%d\n", ans);
}
