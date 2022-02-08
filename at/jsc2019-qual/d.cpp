#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;

int n, f[maxn][maxn], ans;

int main() {
	cin >> n;
	while ((1<<ans) < n) ans++;
	for (int i = 0; i < ans; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k)
				if (((j>>i)&1) == 0 && ((k>>i)&1) == 1)
					f[j][k] = i+1;
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j)
			printf("%d ", f[i][j]);
		puts("");
	}
}
