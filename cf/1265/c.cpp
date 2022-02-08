#include <bits/stdc++.h>
#define D(x) 0&&(cout << #x << " = " << x << endl)
using namespace std;

void solve() {
	int n, tot = 0;
	cin >> n;
	vector<int> p(n), l, r, id(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		if (i == 0 || p[i] != p[i-1]) {
			id[i] = tot++;
			D(i), D(id[i]);
			l.push_back(i);
			r.push_back(i);
		}
		else id[i] = id[i-1];
		r[id[i]] = i;
	}
	int T = id[n/2];
	D(T);
	int g = 0, s = 0, b = 0;
	for (int i = 0; i < T-2; ++i) {
		int m = (l[T]+r[i]+1)/2;
		if (min(l[id[m]]-(r[i]+1), l[T]-l[id[m]]) > r[i]+1) {
			g = r[i]+1;
			s = l[id[m]]-(r[i]+1);
			b = l[T]-l[id[m]];
			break;
		}
		if (min(r[id[m]]-r[i], l[T]-(r[id[m]]+1)) > r[i]+1) {
			g = r[i]+1;
			s = r[id[m]]-r[i];
			b = l[T]-(r[id[m]]+1);
			break;
		}
	}
	printf("%d %d %d\n", g, s, b);
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
