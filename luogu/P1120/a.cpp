#include <bits/stdc++.h>
using namespace std;

int n, tot, vis[66];
vector<int> v;

bool dfs(int cnt, int len, int tgt, int last) {
	if (len == tgt) return dfs(cnt+1, 0, tgt, 0);
	if (cnt == tot/tgt) return true;
	int fail = 0;
	for (int i = last; i < n; ++i) {
		if (!vis[i] && v[i] != fail && len+v[i] <= tgt) {
			vis[i] = 1;
			if (dfs(cnt, len+v[i], tgt, i+1)) return true;
			fail = v[i];
			vis[i] = 0;
			if (len+v[i] == tgt || len == 0) return false;
		}
	}
	return false;
}

int main() {
	scanf("%d", &n);
	int x;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x);
		if (x <= 50) {
			v.push_back(x);
			tot += x;
		}
	}
	n = v.size();
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (int i = 1; i <= tot; ++i) {
		memset(vis, 0, sizeof(vis));
		if (tot%i == 0 && dfs(0, 0, i, 0)) {
			printf("%d", i);
			return 0;
		}
	}
}
