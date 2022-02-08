#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e3, width = 1000000000, d = 9, MX = 5e3;

int i, fact[maxn] = {1}, ans[maxn], tmp[d];

int main() {
	int n;
	scanf("%d", &n);
	puts("2.");
	for (i = 2; i < MX; ++i) {
		int carry = 0;
		for (int j = 0; j < maxn; ++j) {
			long long tmp = ((long long)carry*width+fact[j]);
			fact[j] = tmp/i;
			ans[j] += fact[j];
			if (ans[j] >= width) {
				ans[j-1] += ans[j]/width;
				ans[j] %= width;
			}
			carry = tmp%i;
		}
	}
	for (int i = 0; i < n; ++i) {
		int k = i/d+1;
		if (i%d == 0) {
			for (int j = d-1; ~j; --j) {
				tmp[j] = ans[k]%10;
				ans[k] /= 10;
			}
		}
		printf("%d", tmp[i%d]);
		if (i%10 == 9) putchar(' ');
		if (i%50 == 49) putchar('\n');
	}
}
