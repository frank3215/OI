#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn = 10010;
char A[maxn], B[maxn], C[maxn];
int n, m, cnt2, a[maxn], b[maxn];
bool noless() {
	if (n > m) return 1;
	if (n == m) {
		for (int i = n-1; ~i; --i)
			if (a[i] > b[i]) return 1;
			else if (a[i] < b[i]) return 0;
		return 1;
	}
	return 0;
}
void swap() {
	for (int i = 0; i < std::max(n, m); ++i)
		std::swap(a[i], b[i]);
	std::swap(n, m);
}
void minus() {
	bool pre = 0;
	for (int i = 0; i < n; ++i) {
		a[i] -= pre;
		pre = 0;
		if (b[i] > a[i]) {
			a[i] += 10;
			pre = 1;
		}
		a[i] -= b[i];
	}
	while (n && !a[n-1]) --n;
}
void adiv2() {
	bool nxt = 0;
	for (int i = n-1; ~i; --i) {
		a[i] += 10*nxt;
		nxt = 0;
		if (a[i]%2) nxt = 1;
		a[i] /= 2;
	}
	while (n && !a[n-1]) --n;
}
void bdiv2() {
	bool nxt = 0;
	for (int i = m-1; ~i; --i) {
		b[i] += 10*nxt;
		nxt = 0;
		if (b[i]%2) nxt = 1;
		b[i] /= 2;
	}
	while (m && !b[m-1]) --m;
}
void mult2() {
	bool pre = 0;
	for (int i = 0; i <= n; ++i) {
		a[i] *= 2;
		a[i] += pre;
		pre = 0;
		if (a[i] >= 10) {
			pre = 1;
			a[i] -= 10;
		}
	}
	if (a[n]) ++n;
}
void print() {
	for (int i = n-1; ~i; --i) putchar('0'+a[i]);
	putchar('\n');
}
void gcd() {
	while (1) {
//		print(), swap(), print(), swap(), putchar('\n');
		if (n == 0) swap();
		if (m == 0) break;
		if (a[0]%2 == 0 && b[0]%2 == 0) {
			cnt2++;
			adiv2(), bdiv2();
		}
		else if (a[0]%2 == 0) adiv2();
		else if (b[0]%2 == 0) bdiv2();
		else if (a[0]%2 && b[0]%2 && noless()) minus();
		else swap();
	}
	while (cnt2--) mult2();
	print();
}
int main() {
	scanf("%s%s", A, B);
	n = strlen(A), m = strlen(B);
	for (int i = 0; i < n; ++i) a[i] = A[n-1-i]-'0';
	for (int i = 0; i < m; ++i) b[i] = B[m-1-i]-'0';
	gcd();
}
