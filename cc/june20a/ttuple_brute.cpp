#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int N = 11;

int d[N][N][N];

void solve() {
	vi x(3), y(3);
	for (int i = 0; i < 3; ++i) cin >> x[i];
	for (int i = 0; i < 3; ++i) cin >> y[i];
	queue<vi> q;
	q.push(x);
	memset(d, -1, sizeof(d));
	d[x[0]][x[1]][x[2]] = 0;
	while (!q.empty()) {
		x = q.front(); q.pop();
		int dist = d[x[0]][x[1]][x[2]];
		for (int i = 1; i < 8; ++i) {
			for (int k = 1; k <= 10; ++k) {
				vi xx = x;
				bool ok = true;
				for (int j = 0; j < 3; ++j) {
					if ((i>>j)&1) {
						ok &= ((xx[j] += k) <= y[j]);
					}
				}
				if (!ok) break;
				if (d[xx[0]][xx[1]][xx[2]] == -1) {
					q.push(xx);
					d[xx[0]][xx[1]][xx[2]] = dist+1;
				}
			}
			for (int k = 2; k <= 10; ++k) {
				vi xx = x;
				bool ok = true;
				for (int j = 0; j < 3; ++j) {
					if ((i>>j)&1) {
						ok &= ((xx[j] *= k) <= y[j]);
					}
				}
				if (!ok) break;
				if (d[xx[0]][xx[1]][xx[2]] == -1) {
					q.push(xx);
					d[xx[0]][xx[1]][xx[2]] = dist+1;
				}
			}
		}
	}
	printf("%d\n", d[y[0]][y[1]][y[2]]);
}

signed main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
}
