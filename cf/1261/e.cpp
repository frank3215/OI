#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	char ans[n+1][n+1] = {};
	set<pair<int,int> > s;
	s.insert(make_pair(0, n));
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (!s.empty()) {
			auto p = s.begin();
			int l = p->first, r = p->second;
			int m = max(l+1, r-a[i]+1), cnt = r-m+1;
			for (int j = l; j <= r; ++j) {
				ans[j][i] = '0'+(j>=m);
			}
			for (int j = 0; j < l; ++j) {
				ans[j][i] = '0'+(j<a[i]-cnt);
			}
			for (int j = r+1; j <= n; ++j) {
				ans[j][i] = '0'+(j-(r-l+1)<a[i]-cnt);
			}
			if (m-l >= 2) s.insert(make_pair(l, m-1));
			if (r-m+1 >= 2) s.insert(make_pair(m, r));
			s.erase(p);
		}
		else {
			for (int j = 0; j <= n; ++j) {
				ans[j][i] = '0'+(j<a[i]);
			}
		}
	}
	cout << n+1 << endl;
	for (int i = 0; i < n+1; ++i)
		cout << ans[i] << endl;
}
