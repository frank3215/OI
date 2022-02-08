#include <bits/stdc++.h>
#define x e[i].first
#define y e[i].second
using namespace std;

const int maxn = 10010;
int n;
int vis[maxn], ans[maxn], a[maxn], sum;
pair<int, int> e[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n-1; ++i)
		scanf("%d%d", &x, &y);
	for (int i = 0; i < n; ++i) scanf("%d", a+i), sum+=a[i];
	sort(a, a+n);
	sum -= a[n-1];
	vis[1] = 1;
	ans[1] = a[n-1];
	for (int j = n-2; ~j; --j)
		for (int i = 0; i < n-1; ++i)
			if (vis[x]+vis[y] == 1) {
				ans[vis[x]?y:x] = a[j];
				vis[x] = vis[y] = 1;
				break;
			}
	printf("%d\n", sum);
	for (int i = 1; i <= n; ++i) {
		printf("%d ", ans[i]);
	}
}
