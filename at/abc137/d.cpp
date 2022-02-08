#include <bits/stdc++.h>
#define a first
#define b second
using namespace std;

const int maxn = 1e5+10;

int n, m, ans;
pair<int, int> x[maxn];
priority_queue<int> pq;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> x[i].a >> x[i].b;
	sort(x, x+n);
	for (int i = 0, j = 1; j <= m; ++j) {
		for (; i < n && x[i].a <= j; ++i) pq.push(x[i].b);
		if (!pq.empty()) ans += pq.top(), pq.pop();
	}
	cout << ans;
}
