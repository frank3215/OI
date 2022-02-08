#include <bits/stdc++.h>
using namespace std;

signed main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		printf("%d %d\n", 2*i%n+1, (2*i+1)%n+1);
	}
}
