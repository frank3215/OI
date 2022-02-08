#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pos;

int n, m;

int main() {
	scanf("%d%d", &n, &m);
	int l = 1, r = n;
	while (l < r) {
		for (int i = 1; i <= m; ++i) {
			printf("%d %d\n", l, i);
			printf("%d %d\n", r, m+1-i);
		}
		l++, r--;
	}
	if (l == r) {
		for (int i = 1; i <= m; ++i) {
			if (i%2 == 1) printf("%d %d\n", l, (i+1)/2);
			if (i%2 == 0) printf("%d %d\n", l, m+1-i/2);
		}
	}
}
