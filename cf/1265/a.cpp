#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;

int n;
char s[maxn];

void solve() {
	scanf("%s", s+1);
	n = strlen(s+1);
	bool ok = 1;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '?') {
			for (char j = 'a'; j <= 'c'; ++j)
				if (s[i-1] != j && s[i+1] != j) {
					s[i] = j;
					break;
				}
		} else if (s[i] == s[i-1]) ok = 0;
	}
	if (ok) printf("%s\n", s+1);
	else puts("-1");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
}
