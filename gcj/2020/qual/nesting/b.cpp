#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int t, n;
char s[N];

void solve(int l, int r, int k) {
	if (l > r) return;
	for (int i = l; i <= r; ++i) {
		if (s[i]-'0' == k) {
			solve(l, i-1, k), putchar(s[i]), solve(i+1, r, k);
			return;
		}
	}
	putchar('('), solve(l, r, k+1), putchar(')');
}

int main() {
	scanf("%d", &t);
	for (int _ = 1; _ <= t; ++_) {
		scanf("%s", s);
		printf("Case #%d: ", _);
		n = strlen(s);
		solve(0, n-1, 0);
		putchar('\n');
	}
}
