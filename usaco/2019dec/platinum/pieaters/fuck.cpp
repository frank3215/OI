#include <bits/stdc++.h>
using namespace std;

const int maxn = 55, maxm = 25;

int n, m;
int w[maxm], l[maxm], r[maxm], pie[maxn], p[maxn];
int ans;

bool cmp(int i, int j) { return r[i]-l[i] < r[j]-l[j]; }

int main() {
	freopen("pieaters.in", "r", stdin);
	freopen("pieaters.ans", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", w+i, l+i, r+i);
		p[i] = i;
	}
	do {
		memset(pie, 0, sizeof(pie));
		for (int i = 0, W = 0; i < m; ans=max(ans,W+=w[p[i]]), ++i) {
			bool ok = false;
//			printf(" %d\n", w[p[i]]);
			for (int j = l[p[i]]; j <= r[p[i]]; ++j)
				if (!pie[j]) ok = pie[j] = true;
			if (!ok) break;
		}
//		printf("%d\n", ans);
	} while (next_permutation(p, p+m));
	printf("%d\n", ans);
}
