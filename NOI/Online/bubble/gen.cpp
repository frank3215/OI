#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;

int p[maxn];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d %d\n", n, m);
	for (int i = 0; i < n; ++i) {
		p[i] = i+1;
	}
	random_shuffle(p, p+n);
	for (int i = 0; i < n; ++i) {
		printf("%d%c", p[i], " \n"[i+1==n]);
	}
	for (int i = 0; i < m; ++i) {
		int t = rand()%2+1, c;
		if (t == 1) c = rand()%(n-1)+1;
		else c = rand()%n;
		printf("%d %d\n", t, c);
	}
}
