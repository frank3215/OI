#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
const int maxn = 10000+10;

int cnt2;
struct big{
	const static int MAX = 10, W = 1;
	int a[maxn/W], n;
	int size() const {
		return n;
	}
	bool empty() const {
		return !n;
	}
	int operator [](const int &i) const {
		return a[i];
	}
	void operator =(char *s) {
		int t, len = strlen(s);
		for (int i = len; i > 0; i -= W) {
			int l = std::max(i-W, 0), tmp = s[i];
			s[i] = '\0';
			sscanf(s+l, "%d", &t);
			s[i] = tmp;
			a[n++] = t;
		}
	}
	void operator =(big &b) {
		memcpy(a, b.a, sizeof(b.a));
		n = b.n;
	}
	void print() {
		for (int i = n-1; ~i; --i) printf("%d", a[i]);
		putchar('\n');
	}
	bool operator >=(const big &b) {
		if (n > b.size()) return 1;
		if (n == b.size()) {
			for (int i = n-1; ~i; --i)
				if (a[i] > b[i]) return 1;
				else if (a[i] < b[i]) return 0;
			return 1;
		}
		return 0;
	}
	void operator -=(const big &b) {
		bool pre = 0;
		for (int i = 0; i < n; ++i) {
			a[i] -= pre;
			if (i < b.size() && b[i] > a[i]) {
				a[i] += MAX;
				pre = 1;
			}
			else pre = 0;
			a[i] -= b[i];
		}
		while (n && !a[n-1]) --n;
	}
	void div2() {
		bool nxt = 0;
		for (int i = n-1; ~i; --i) {
			a[i] += MAX*nxt;
			if (a[i]%2) nxt = 1;
			else nxt = 0;
			a[i] /= 2;
		}
		while (n && !a[n-1]) --n;
	}
	void mult2() {
		bool pre = 0;
		for (int i = 0; i < n; ++i) {
			a[i] *= 2;
			a[i] += pre;
			if (a[i] >= MAX) {
				pre = 1;
				a[i] -= MAX;
			}
			else pre = 0;
		}
		if (pre) a[n++] = pre;
	}
}a, b, t;
void swap() {
	t = a;
	a = b;
	b = t;
}
void gcd() {
	while (1) {
//		a.print(), b.print(), putchar('\n');
		if (a.empty()) swap();
		if (b.empty()) break;
		if (a[0]%2 == 0 && b[0]%2 == 0) {
			cnt2++;
			a.div2(), b.div2();
		}
		else if (a[0]%2 == 0) a.div2();
		else if (b[0]%2 == 0) b.div2();
		else if (a[0]%2 && b[0]%2) {
			if (a >= b) a -= b;
			else b -= a;
		}
	}
	while (cnt2--) a.mult2();
	a.print();
}
int main() {
	std::cin >> A >> B;
	a = A, b = B;
	gcd();
}
