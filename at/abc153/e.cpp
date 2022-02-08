#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3+10, maxh = 1e4+10;
int h, n;
int a[maxn], b[maxn], f[maxh];

int main() {
	cin >> h >> n;
	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		for (int j = 0; j <= h; ++j) {
			if (j <= a[i]) f[j] = min(f[j], b[i]);
			else f[j] = min(f[j], b[i]+f[j-a[i]]);
		}
	}
	cout << f[h] << endl;
	return 0;
}
