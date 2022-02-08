#include <bits/stdc++.h>
using namespace std;

int n, x[50], y[50];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", x+i, y+i);
	}
	int ans = n;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			int p = x[i]-x[j], q = y[i]-y[j];
			if (p == 0 && q == 0) continue;
			int cost = n;
			for (int k = 0; k < n; ++k) {
				for (int l = 0; l < n; ++l) {
					if (x[k]-x[l] == p && y[k]-y[l] == q) {
						cost--;
						break;
					}
				}
			}
			ans = min(ans, cost);
		}
	}
	printf("%d\n", ans);
}
