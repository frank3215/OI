#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n;
int s[N], e[N], p[N];
bool ans[N];

bool cmp(int i, int j) {
	return s[i] < s[j];
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", s+i, e+i);
		p[i] = i;
	}
	sort(p, p+n, cmp);
	int C = 0, J = 0;
	for (int i = 0; i < n; ++i) {
		if (s[p[i]] >= C) {
			ans[p[i]] = 0;
			C = e[p[i]];
		} else if (s[p[i]] >= J) {
			ans[p[i]] = 1;
			J = e[p[i]];
		} else {
			puts("IMPOSSIBLE");
			return;
		}
	}
	for (int i = 0; i < n; ++i) {
		putchar(ans[i]?'J':'C');
	}
	putchar('\n');
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
}
