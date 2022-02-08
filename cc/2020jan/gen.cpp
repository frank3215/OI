#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 1e5, q = n-1;
	printf("%d %d\n", n, q);
	for (int i = 1; i <= n; ++i)
		printf("%d ", i);
	printf("\n");
	for (int i = 1; i < n; ++i)
		printf("%d %d\n", i, i+1);
}
