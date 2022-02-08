#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 1e4, m = n;
	printf("%d %d\n", n, m);
	while (m--) {
		int l = rand()%n+1, r = rand()%n+1;
		if (l > r) swap(l, r);
		printf("%d %d\n", l, r);
	}
}
