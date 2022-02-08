#include <bits/stdc++.h>
using namespace std;

const int maxa = 1e5;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d %d\n", n, m);
	for (int i = 0; i < n; ++i) {
		printf("%d%c", rand()%maxa+1, " \n"[i+1==n]);
	}
	for (int i = 0; i < m; ++i) {
		printf("%d\n", i);
	}
}
