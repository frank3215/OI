#include <bits/stdc++.h>
using namespace std;

char a[4], b[4];
int ans;

int main() {
	scanf("%s%s", a, b);
	for (int i = 0; i < 3; ++i)
		ans += a[i] == b[i];
	printf("%d\n", ans);
}
