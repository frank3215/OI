#include <cstdio>
#include <iostream>
int main() {
	int n, a[16];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 0; i < (1 << n); ++i) {
		int sum[2] = {0, 0};
		for (int j = 0; j < n; ++j) {
			sum[(bool) (i & (1 << j))] += a[j];
		}
		if (sum[1] % 360 == sum[0] % 360) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}
