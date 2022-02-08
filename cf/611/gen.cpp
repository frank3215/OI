#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+10;

int n;
int p[maxn];

void out(int x) {
	for (; x; x /= 10) putchar('?');
}

int main() {
	srand(time(NULL));
	scanf("%d", &n);
	printf("%d\n", n);
	for (int i = 1; i <= n; ++i) {
		p[i] = i;
	}
	random_shuffle(p+1, p+n+1);
	for (int i = 2; i <= n; ++i) {
		int fa = rand()%(i-1)+1;
		out(p[i]), putchar(' '), out(p[fa]), putchar('\n');
	}
}
