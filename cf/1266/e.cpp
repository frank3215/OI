#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

int n, a[N], ans[N];
long long Ans;
map<int,int> mp[N];
int q, cnt[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
		ans[i] = a[i];
		Ans += ans[i];
	}
	scanf("%d", &q);
	while (q--) {
		int s, t, u;
		scanf("%d%d%d", &s, &t, &u);
		int x = mp[s][t];
		if (x) {
			Ans -= ans[x];
			ans[x] = max(0, a[x] - --cnt[x]);
			Ans += ans[x];
			mp[s][t] = 0;
		}
		if (u) {
			mp[s][t] = u;
			Ans -= ans[u];
			ans[u] = max(0, a[u] - ++cnt[u]);
			Ans += ans[u];
		}
		printf("%lld\n", Ans);
	}
}
