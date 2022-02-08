#include <bits/stdc++.h>
using namespace std;

int n, a;
long long b[2];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		b[i%2] += (a+1)/2;
		b[(i+1)%2] += a/2;
	}
	printf("%lld", min(b[0], b[1]));
}
