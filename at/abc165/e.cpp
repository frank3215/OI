#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
	scanf("%d%d", &n, &m);
	int x = (m+1)/2, y = m/2;
	for (int i = 1; i <= x; ++i) {
		printf("%d %d\n", i, 2*x+1-i);
	}
	for (int j = 1; j <= y; ++j) {
		printf("%d %d\n", 2*x+j, 2*x+2*y+2-j);
	}
}
