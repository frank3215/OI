#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, l, r, L = 1e9, R = 1;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &l, &r);
			L = min(L, r);
			R = max(R, l);
		}
		printf("%d\n", max(0, R-L));
	}
}
