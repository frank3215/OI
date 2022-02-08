#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;

deque<int> q;
vector<pair<int, int> > v;

int n, a, b, arr[maxn], mx, Q;
long long m;

int main() {
	scanf("%d%d", &n, &Q);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		mx = max(mx, a);
		q.push_back(a);
	}
	for (int i = 0; ; ++i) {
		a = q.front();
		if (a == mx) break;
		q.pop_front();
		b = q.front(); q.pop_front();
		v.push_back(make_pair(a, b));
		if (a < b) swap(a, b);
		q.push_front(a);
		q.push_back(b);
	}
	for (int i = 0; i < n; ++i) {
		arr[i] = q.front();
		q.pop_front();
	}
	while (Q--) {
		scanf("%lld", &m);
		if (m <= v.size()) printf("%d %d\n", v[m-1].first, v[m-1].second);
		else {
			printf("%d %d\n", arr[0], arr[(m-v.size()-1)%(n-1)+1]);
		}
	}
}
