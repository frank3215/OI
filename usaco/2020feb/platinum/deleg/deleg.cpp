#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;

int n;
vector<int> to[maxn];
typedef multiset<int>::iterator IT;
int k;

int ok(multiset<int> s) {
	int last = 0;
	for (IT i = s.begin(), j; i != s.end(); s.erase(i++)) {
/*
		if (*i >= k) {
			if (!last) last = *i;
			continue;
		}
*/
		j = s.lower_bound(k-*i);
		if (j == i) ++j;
		if (j == s.end()) {
			if (last) {
				return -1;
			} else {
				last = *i;
			}
		} else {
			s.erase(j);
		}
	}
	return last;
}

int dfs(int u, int fa) {
	multiset<int> s;
	for (auto v: to[u]) if (v != fa) {
		int tmp = dfs(v, u);
		if (tmp == -1) return -1;
		s.insert(tmp+1);
	}
	int last = -1;
	if (fa == 0) {
		if (s.size()%2) s.insert(0);
		return ok(s);
	}
	if (s.size()%2 == 0) {
		last = max(last, ok(s));
		s.insert(0);
	}
	last = max(last, ok(s));
//	assert(s.empty());
//	printf("%d(%d) %d\n", u, fa, min(k,last));
	return last;
}

bool check(int K) {
	k = K;
	int ret = dfs(1, 0);
	return ret != -1;
}

int main() {
//	freopen("deleg.in", "r", stdin);
//	freopen("deleg.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n-1; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		to[u].push_back(v);
		to[v].push_back(u);
	}
	int l = 1, r = n-1;
	while (l < r) {
		int mid = (l+r+1)/2;
		printf("%d %d %d\n", l, mid, r);
		if (check(mid)) l = mid;
		else r = mid-1;
	}
	printf("%d\n", r);
}
