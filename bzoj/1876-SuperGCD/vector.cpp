#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
const int maxn = 10010;
std::string A, B;
int cnt2;
struct big{
	const static int MAX = 1e9, W = 9;
	std::vector<int> a;
	unsigned size() const {
		return a.size();
	}
	bool empty() const {
		return a.empty();
	}
	int operator [](const int &i) const {
		return a[i];
	}
	void operator =(std::string s) {
		int n;
		for (int i = s.size(); i > 0; i -= W) {
			int l = std::max(i-W, 0), len = i-l;
			sscanf(s.substr(l, len).c_str(), "%d", &n);
			a.push_back(n);
		}
	}
	void operator =(big &b) {
		a = b.a;
	}
	void print() {
		printf("%d", a.back());
		for (int i = a.size()-2; ~i; --i) printf("%09d", a[i]);
		putchar('\n');
	}
	bool operator >=(const big &b) {
		if (a.size() > b.size()) return 1;
		if (a.size() == b.size()) {
			for (int i = a.size()-1; ~i; --i)
				if (a[i] > b[i]) return 1;
				else if (a[i] < b[i]) return 0;
			return 1;
		}
		return 0;
	}
	void operator -=(const big &b) {
		bool pre = 0;
		for (int i = 0; i < a.size(); ++i) {
			a[i] -= pre;
			if ((i < b.size() && b[i] > a[i]) || (i >= b.size() && a[i] < 0)) {
				a[i] += MAX;
				pre = 1;
			}
			else pre = 0;
			if (i < b.size()) a[i] -= b[i];
		}
		while (!a.empty() && !a.back()) a.pop_back();
	}
	void div2() {
		bool nxt = 0;
		for (int i = a.size()-1; ~i; --i) {
			a[i] += MAX*nxt;
			if (a[i]%2) nxt = 1;
			else nxt = 0;
			a[i] /= 2;
		}
		while (!a.empty() && !a.back()) a.pop_back();
	}
	void mult2() {
		bool pre = 0;
		for (int i = 0; i < a.size(); ++i) {
			a[i] *= 2;
			a[i] += pre;
			if (a[i] >= MAX) {
				pre = 1;
				a[i] -= MAX;
			}
			else pre = 0;
		}
		if (pre) a.push_back(pre);
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
