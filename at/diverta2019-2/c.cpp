#include <bits/stdc++.h>
using namespace std;

int n, m, p, b, c, ans;
int a[100010];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a+i);
	}
	sort(a, a+n);
	m = lower_bound(a, a+n, 0)-a;
	if (!m) m++;
	if (m == n) m--;
	for (int i = 0; i < n; ++i) {
		ans += (i<m)?-a[i]:a[i];
	}
	printf("%d\n", ans);
	for (int i = 1; i < n-m; ++i) {
		printf("%d %d\n", a[0], a[n-i-1]);
		a[0] -= a[n-i-1];
	}
	for (int i = 0; i < m; ++i) {
		printf("%d %d\n", a[n-1], a[i]);
		a[n-1] -= a[i];
	}
}
