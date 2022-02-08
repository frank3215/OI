#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	int x[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", x+i);
	}
	int minans = n+1, maxans = 0;
	for (int i = 0; i < n; ++i) {
		int cur[n] = {};
		cur[i] = 1;
		bool flag;
		int cnt = 1;
		do {
			flag = false;
			for (int j = 0; j < n; ++j) if (cur[j]) {
				for (int k = 0; k < n; ++k) if (!cur[k] && abs(x[j]-x[k]) <= 2) {
					cur[k] = 1;
					flag = true;
					++cnt;
				}
			}
		} while (flag);
		minans = min(minans, cnt);
		maxans = max(maxans, cnt);
	}
	printf("%d %d\n", minans, maxans);
}

int main() {
	int n;
	scanf("%d", &n);
	while (n--) solve();
}
