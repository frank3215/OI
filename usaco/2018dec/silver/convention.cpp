#include <cstdio>
#include <algorithm>
const int maxn = 1e5+10;
int n,m,c,t[maxn];
bool ok(int time) {
	int cur=0;
	for (int i = 0; i < m; ++i) {
		int num=0;
		while(num < c && cur + num < n && t[cur + num] - t[cur] <= time) ++num;
		cur+=num;
	}
//	printf("%d %d %d\n",time,cur,n);
	if (cur == n) return true;
	return false;
}
int main() {
	freopen("convention.in", "r", stdin);
	freopen("convention.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &c);
	for (int i = 0; i < n; ++i) {
		scanf("%d", t+i);
	}
	std::sort(t, t + n);
	int l = 0, r = 1e9 + 10;
	while (l < r) {
		int mid = l + r >> 1;
		if (ok(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);
}
