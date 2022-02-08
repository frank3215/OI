#include <bits/stdc++.h>
using namespace std;

const int maxn = 100+10;

int n, m;
int a[maxn], b[maxn];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
	}
	for (int i = 1; i <= m; ++i) {
		int t, c;
		scanf("%d%d", &t, &c);
		if (t == 1) swap(a[c], a[c+1]);
		else {
			memcpy(b, a, sizeof(b));
			for (int i = 0; i < c; ++i)
				for (int j = 1; j < n; ++j)
					if (b[j] > b[j+1]) swap(b[j], b[j+1]);
			int ans = 0;
			for (int i = 1; i <= n; ++i)
				for (int j = i+1; j <= n; ++j)
					if (b[i] > b[j]) ans++;
			printf("%d\n", ans);
		}
	}
}
