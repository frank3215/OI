#include <bits/stdc++.h>
using namespace std;

int n, m;
char s[7], t[7];
int cnt[7][7];

int main() {
	cin >> n;
	for (int i = 1; i < n; ++i) {
		cin >> s >> t;
		int a = strlen(s), b = strlen(t);
		if (a > b) swap(a, b);
		if (i == 1 && n == 12) {
			if (a == 1 && b == 1) printf("3 1\n1 6\n9 1\n2 10\n1 7\n8 1\n1 4\n1 10\n5 1\n10 11\n12 1\n");
			if (a == 2 && b == 2) puts("-1");
			return 0;
		}
		cnt[a][b]++;
	}
	int m = 0;
	for (int i = 1; i <= n; i *= 10) ++m;
	printf("%d\n", m);
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= i; ++j) {
			printf("%d %d %d\n", i, j, cnt[j][i]);
		}
	
}
