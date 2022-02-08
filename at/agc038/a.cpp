#include <bits/stdc++.h>
using namespace std;

int h, w, a, b;

int main() {
	scanf("%d%d%d%d", &h, &w, &a, &b);
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j)
			printf("%d", (i<b)^(j<a));
		putchar('\n');
	}
}
