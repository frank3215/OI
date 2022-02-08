#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;

int n, a[maxn], b[maxn];


int main() {
	scanf("%d", &n);
	long long asum = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a+i);
		asum += a[i];
	}
	long long bsum = 0;
	for (int i = 2; i < 2*n; i+=2) {
		b[i%n] = a[(i-1)%n]-a[(i-2)%n]+b[(i-2)%n];
		bsum += b[i%n];
//		printf("%d %d\n", i%n, b[i%n]);
	}
	b[0] = (asum-2*bsum)/2/n;
	printf("%d", b[0]*2);
	for (int i = 1; i < n; ++i) {
		b[i] += b[0];
		printf(" %d", b[i]*2);
	}
}
