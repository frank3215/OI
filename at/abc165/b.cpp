#include <bits/stdc++.h>
using namespace std;

long long n, x = 100;

int main() {
	scanf("%lld", &n);
	for (int i = 0; ; ++i) {
		if (x >= n) return printf("%d\n", i), 0;
		x += x/100;
	}
}
