#include <bits/stdc++.h>

const int maxn = 1e5+1, maxlg = 18;

int n, m;
int a[maxn];
int lg[maxn], pw[maxlg], st[maxlg][maxn];
int l, r;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", a+i);

	lg[1] = 0;
	for (int i = 2; i <= n; ++i) lg[i] = lg[i/2]+1;
	pw[0] = 1;
	for (int i = 1; i <= lg[n]; ++i) pw[i] = pw[i-1]*2;

	for (int i = 1; i <= n; ++i) st[0][i] = a[i];
	for (int j = 1; j <= lg[n]; ++j)
		for (int i = 1; i <= n-pw[j]+1; ++i)
			st[j][i] = std::max(st[j-1][i], st[j-1][i+pw[j-1]]);

	while (m--) {
		scanf("%d%d", &l, &r);
		int k = lg[r-l+1];
		printf("%d\n", std::max(st[k][l], st[k][r-pw[k]+1]));
	}

}
