#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 5e5, seed, sigma = 26;
	scanf("%d", &seed);
	printf("%d\n", n);
	srand(seed%998244353);
	for (int i = 2; i <= n; ++i) {
		printf("%d%c", rand()%(i-1)+1, " \n"[i==n]);
	}
	for (int i = 1; i <= n; ++i) putchar('a'+rand()%sigma);
}
