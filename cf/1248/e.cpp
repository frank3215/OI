#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e5;

int n, p, a;
ll cur;
queue<int> q;
multiset<pii> sp;
multiset<int> si;
vector<ll> ans(maxn);

void proc1() {
	if (sp.empty()) return;
	a = sp.begin()->second;
	cur = sp.begin()->first;
	sp.erase(sp.begin());
	q.push(a);
}

signed main() {
	cin >> n >> p;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		sp.insert(make_pair(a, i));
	}
	proc1();
	while (!si.empty() || !sp.empty() || !q.empty()) {
		cur += p;
		while (!sp.empty() && sp.begin()->first <= cur) {
			a = sp.begin()->second;
			if (q.empty() || a < q.back()) q.push(a);
			else si.insert(a);
			sp.erase(sp.begin());
		}
		q.pop();
		ans[q.front()] = cur;
		if (q.empty()) {
			if (!si.empty()) {
				q.push(*si.begin());
				si.erase(si.begin());
			} else proc1();
		}
	}
	for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
}
