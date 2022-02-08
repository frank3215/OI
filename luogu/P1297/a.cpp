#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e7+10;

int n, A, B, C, a[maxn];
double ans = 0;

int main() {
	scanf("%d%d%d%d%d", &n, &A, &B, &C, a + 1);
	for (int i = 2; i <= n; i++)
		a[i] = ((long long) a[i - 1] * A + B) % 100000001;
	for (int i = 1; i <= n; i++)
		a[i] = a[i] % C + 1;
	for (int i = 1; i <= n; i++) {
		ans += 1.0*min(a[i], a[i%n+1])/a[i]/a[i%n+1];
	}
	printf("%.3f\n", ans);
}
