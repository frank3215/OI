#include <bits/stdc++.h>
using namespace std;

int t;

void print(vector<int> ans, int n) {
	for (int i = 0; i < n; ++i)
		cout << ans[i] << ' ';
	cout << endl;
}
void solve() {
	int n;
	cin >> n;
	vector<int> a(n), id(n), p(n-1), x(n-1), y(n-1), b, tmp(n), ans(n,n);
	for (int i = 0; i < n; ++i) {
		cin >> id[i];
		a[--id[i]] = i;
	}
	for (int i = 0; i < n-1; ++i) {
		cin >> x[i] >> y[i];
		x[i]--, y[i]--;
		p[i] = i;
	}
	do {
		b = a;
		for (int i = 0; i < n-1; ++i)
			swap(b[x[p[i]]], b[y[p[i]]]);
//		print(p,n-1);
//		print(b,n);
		for (int i = 0; i < n; ++i)
			tmp[b[i]] = i+1;
		ans = min(ans, tmp);
	} while (next_permutation(p.begin(), p.end()));
	print(ans, n);
}

int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.ans", "w", stdout);
	cin >> t;
	while (t--) solve();
}

