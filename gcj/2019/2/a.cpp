#include <bits/stdc++.h>

using namespace std;

const int maxn = 300+10;

int n, m;
int c[maxn], p[maxn];

vector<pair<int, int> > v;

void clean() {
	v.clear();
}

int gcd(int x, int y) {
	return y?gcd(y, x%y):x;
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", c+i, p+i);
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) if (c[i] < c[j] && p[i] > p[j]) {
			int dc = abs(c[i]-c[j]), dp = abs(p[i]-p[j]), g = gcd(dc, dp);
			dc /= g, dp /= g;
			v.push_back(make_pair(dc, dp));
		}
	std::sort(v.begin(), v.end());
	m = std::unique(v.begin(), v.end()) - v.begin();
	printf("%d\n", m+1);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		printf("Case #%d: ", i);
		solve();
		clean();
	}
}
