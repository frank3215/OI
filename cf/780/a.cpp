#include <bits/stdc++.h>
using namespace std;

int n, x, ans;
set<int> s;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 2*n; ++i) {
		scanf("%d", &x);
		if (s.count(x)) s.erase(x);
		else s.insert(x);
		ans = max(ans, (int)s.size());
	}
	printf("%d\n", ans);
}
