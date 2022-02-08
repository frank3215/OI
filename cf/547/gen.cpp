#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5, maxq = 5e5;

int main() {
	int n = 2;
	printf("%d %d\n", n, maxq);
	printf("r\nelxsnfjvgr\n");
	for (int i = 0; i < maxq; ++i) {
		int l = rand()%n+1, r = rand()%n+1, k = rand()%n+1;
		if (l > r) swap(l, r);
		printf("%d %d %d\n", l, r, k);
	}
}
