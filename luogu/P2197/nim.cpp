#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, a, tmp = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a);
			tmp ^= a;
		}
		puts(tmp?"Yes":"No");
	}
}
