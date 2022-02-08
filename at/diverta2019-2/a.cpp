#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	if (k == 1) puts("0");
	else printf("%d\n", (n-k+1)-1);
}
