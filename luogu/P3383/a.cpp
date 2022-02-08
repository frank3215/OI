#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e8+10;

bool nop[maxn];
vector<int> p;

int n, q, k;

void init() {
	for (int i = 2; i <= n; ++i) {
		if (!nop[i]) {
			p.push_back(i);
		}
		for (int j = 0; p[j]*i <= n; ++j) {
			nop[p[j]*i] = 1;
			if (i%p[j] == 0) break;
		}
	}
}

int main() {
	scanf("%d", &n);
	init();
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &k);
		printf("%d\n", p[k-1]);
	}
}
