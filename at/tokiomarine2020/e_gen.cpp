#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 50, k = 50, s = 0, t = (1<<18)-1;
	printf("%d %d %d %d\n", n, k, s, t);
	for (int i = 0; i < 18; ++i) {
		printf("%d %d ", 1<<i, t^(1<<i));
	}
	for (int i = 37; i <= n; ++i) {
		printf("%d%c", rand()%(1<<18), " \n"[i==n]);
	}
}
