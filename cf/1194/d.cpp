#include <bits/stdc++.h>

int main() {
	int t;
	scanf("%d", &t);
	int n, k;
	while (t--) {
		scanf("%d%d", &n, &k);
		if (k%3) {
			puts((n%3)?"Alice":"Bob");
		}
		else {
			int r = n%(k+1);
			if (r == k || r%3 != 0) puts("Alice");
			else puts("Bob");
		}
	}
}
