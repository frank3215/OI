#include <bits/stdc++.h>
using namespace std;

int n, k, s;

bool ok(int s) {
	char num[12];
	sprintf(num, "%d", s);
	for (int i = 0; num[i]; ++i)
		if (num[i] != num[i%k]) return false;
	return true;
}

int main() {
	scanf("%d%d%d", &n, &k, &s);
	do {
		if (ok(s)) break;
	} while (++s);
	printf("%d\n%d",n,s);
}
