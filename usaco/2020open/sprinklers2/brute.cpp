#include <bits/stdc++.h>
using namespace std;

co

int a[N][N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", a[i]);
	}
	printf("%d\n", dfs(0, 0));
}
