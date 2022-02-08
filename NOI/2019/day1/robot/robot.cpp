#include <bits/stdc++.h>
using namespace std;

const int maxn = 310;

int n;
int a[maxn], b[maxn], c[maxn];
int ans;

void print() {
	for (int i = 1; i <= n; ++i) printf("%d ", c[i]); putchar('\n');
}

bool check() {
	bool ok = true;
	for (int i = 1; i <= n; ++i) {
		int j = i, k = i;
		while (j > 1 && c[j-1] <= c[i]) j--;
		while (k < n && c[k+1] < c[i]) k++;
		ok &= (abs((k-i)-(i-j)) <= 2);
//		printf("%d %d %d: %d\n", j, i, k, ok);
	}
//	if (ok) print();
	return ok;
}

void dfs(int i) {
	if (i == n+1) {
		ans += check();
		return;
	}
	for (int j = a[i]; j <= b[i]; ++j) {
		c[i] = j;
		dfs(i+1);
	}
}

int main() {
	freopen("robot.in", "r", stdin);
	freopen("robot.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", a+i, b+i);
	}
	if (n <= 7) {
		dfs(1);
		printf("%d\n", ans);
	}
}
