#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010;

int n, m, a[3], b[3];
int ab[maxn];
long long ba[maxn*maxn];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 3; ++i) scanf("%d", a+i);
	for (int i = 0; i < 3; ++i) scanf("%d", b+i);
	for (int i = 1; i <= n; ++i) {
		ab[i] = ab[i-1];
		for (int j = 0; j < 3; ++j) if (a[j] <= i) {
			ab[i] = max(ab[i], ab[i-a[j]]+(b[j]-a[j]));
		}
	}
	m = n+ab[n];
	for (int i = 1; i <= m; ++i) {
		ba[i] = ba[i-1];
		for (int j = 0; j < 3; ++j) if (b[j] <= i) {
			ba[i] = max(ba[i], ba[i-b[j]]+(a[j]-b[j]));
		}
	}
	printf("%lld\n", m+ba[m]);
}
