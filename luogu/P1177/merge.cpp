#include <bits/stdc++.h>

const int maxn = 1e5+10;
int n;
int a[2][maxn], b[maxn];

void merge(int l, int r, bool k) {
	if (r-l == 1) return void(a[k][l]=b[l]);
	int m = (l+r)>>1;
	merge(l, m, !k);
	merge(m, r, !k);
	for (int ptl = l, ptr = m; ptl < m || ptr < r; ) {
		while (ptl < m && (ptr == r || a[!k][ptl] <= a[!k][ptr])) {
			a[k][ptl+ptr-m] = a[!k][ptl];
			ptl++;
		}
		while (ptr < r && (ptl == m || a[!k][ptr] <= a[!k][ptl])) {
			a[k][ptl+ptr-m] = a[!k][ptr];
			ptr++;
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", b+i);
	merge(0, n, 0);
	for (int i = 0; i < n; ++i)
		printf("%d ", a[0][i]);
}
