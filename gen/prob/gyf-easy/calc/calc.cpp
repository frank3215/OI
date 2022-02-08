#include <bits/stdc++.h>
using namespace std;

long double ans;
char s[10];

int main() {
	int n, p, t;
	scanf("%d%d%d", &n, &p, &t);
	n = min(1000000, n);
	for (int i = 1; i <= n; ++i) ans += pow(1.0F/i, p);
	sprintf(s, "%%.%dLf\n", t);
	printf(s, ans);
}
