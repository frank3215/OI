#include <bits/stdc++.h>
using namespace std;

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &op, &x);
		if (op == 1) {
			insert(rt, x);
		}
		if (op == 2) {
			del(rt, x);
		}
		if (op == 3) {
			printf("%d", rank(rt, x));
		}
		if (op == 4) {
			printf("%d", kth(rt, x));
		}
		if (op == 5) {
			printf("%d", pre(rt, x));
		}
		if (op == 6) {
			printf("%d", nxt(rt, x));
		}
	}
}

