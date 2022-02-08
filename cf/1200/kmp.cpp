#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+10;

char s1[maxn], s2[maxn];
int n, m, nxt[maxn];

int main() {
	scanf(" %s", s1);
	scanf(" %s", s2);
	n = strlen(s1);
	m = strlen(s2);
	nxt[0] = -1;
	for (int i = 0, j; i < m; ++i) {
		for (j = nxt[i]; j >= 0 && s2[j] != s2[i]; j = nxt[j]);
		nxt[i+1] = ++j;
//		printf("%d ", nxt[i]);
	}
	for (int i = 0, j = 0; i <= n; ++i) {
		for (; j >= 0 && s2[j] != s1[i]; j = nxt[j]);
		if (++j == m) {
			printf("%d\n", i-j+2);
			j = nxt[j];
		}
	}
	for (int i = 1; i <= m; ++i)
		printf("%d ", nxt[i]);
}
