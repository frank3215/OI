#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> ans(n);
	vector<pair<int,int> > v;
	set<int> s;
	int l, r;
	for (int i = 1; i <= n; ++i) {
		cin >> l >> r;
		v.emplace_back(l,-i);
		v.emplace_back(r,i);
	}
	int cnt = 0;
	sort(v.begin(), v.end());
	for (auto p : v) {
		int cur = abs(p.second)-1;
		if (p.second < 0) {
			if (s.size() == 1)
				ans[*s.begin()]++;
			else if (s.empty()){
				cnt++;
				ans[cur]--;
			}
			s.insert(cur);
		} else {
			s.erase(cur);
		}
	}
	cout << cnt + *max_element(ans.begin(), ans.end()) << endl;
}
int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
