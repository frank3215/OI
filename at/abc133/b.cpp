#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-6;

inline int sqr(int x) { return x*x; }

int main() {
	int n, d;
	int x[11][11];
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < d; ++j) {
			scanf("%d", &x[i][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			double dist = 0;
			for (int k = 0; k < d; ++k) {
				dist += sqr(x[i][k]-x[j][k]);
			}
			if (sqr((int)(sqrt(dist)+eps)) == dist) ans++;
		}
	}
	printf("%d\n", ans);
}
