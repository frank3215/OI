#include <bits/stdc++.h>
using namespace std;

const int N = 100001;
int a[N];

struct range{
	int b[N], r[N], l[N], s[N], tot, L;
	void add(int R) {
		++tot;
		s[tot] = s[tot-1]+(R-L>0);
		for (int i = L; i <= R; ++i) b[i] = tot;
		r[tot] = R, l[tot] = L;
		L = R+1;
	}
	int query(int L, int R) {
		if (b[L] == b[R]) return 1;
		return s[b[R]-1]-s[b[L]]+(R-l[b[R]]>0)+(r[b[L]]-L>0);
	}
	void print() {
		for (int i = 1; i <= tot; ++i) {
			cerr << l[i] << ' ' << r[i] << ' ' << s[i] << endl;
		}
	}
}s, t;

signed main() {
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (i) {
			if (a[i] < a[i-1]) s.add(i-1);
			if (a[i] > a[i-1]) t.add(i-1);
		}
	}
	s.add(n-1), t.add(n-1);
//	s.print(), t.print();
	int l, r;
	while (q--) {
		cin >> l >> r; --l, --r;
//		cerr << s.query(l,r) << ' ' << t.query(l,r) << endl;
		cout << (s.query(l,r)==t.query(l,r)?"YES":"NO") << endl;
	}
}
