#include <bits/stdc++.h>
using namespace std;

int n, k;
long long m;
int h[100];

void solve() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) cin >> h[i];
	for (int i = 1; i < n; ++i) {
		if ((m += h[i-1]-max(0, h[i]-k)) < 0) {
			puts("NO");
			return;
		}
	}
	puts("YES");
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
