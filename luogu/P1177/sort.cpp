#include <bits/stdc++.h>
using std::swap;

const int maxn = 1e5;
int n, a[maxn];

void sort(int l, int r) {
	if (r-l <= 1) return;
	int x = a[(l+r)/2];
	int ptl = l, ptr = r;
	for (int i = l; i < r; ++i) {
		if (a[i] < x || (a[i] == x && rand()&1)) {
			swap(a[ptl++], a[i]);
		}
	}
	sort(l, ptl);
	sort(ptl, r);
}

void sort2(int l, int r) {
	if (r <= l) return;
	int x = a[(l+r)/2];
	int ptl = l, ptr = r;
//	printf("[%d, %d)\n", l, r);
	do {
//		printf("%d, %d\n", ptl, ptr);
		while (ptl <= r && a[ptl] < x) ptl++;
		while (ptr >= l && a[ptr] > x) ptr--;
		if (ptl <= ptr) {
			swap(a[ptl], a[ptr]);
			ptl++, ptr--;
		}
	} while (ptl <= ptr);
	sort2(l, ptl-1);
	sort2(ptl, r);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a+i);
	}
	sort2(0, n-1);
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
}
