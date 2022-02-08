#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		int l, r, n = 0;
		cin >> l >> r;
		while (1) {
			++n;
			if (n > l && n > r) {
				--n;
				break;
			}
			if (l >= r) l -= n;
			else r -= n;
		}
		printf("Case #%d: %d %d %d\n", i, n, l, r);
	}
}
