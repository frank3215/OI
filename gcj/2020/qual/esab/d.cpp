#include <bits/stdc++.h>
using namespace std;

const int B = 105;

int t, b;
bool a[B];
int len;

void rev() { for (int i = 1; i <= b/2; ++i) swap(a[i], a[b+1-i]); }
void flip() { for (int i = 1; i <= b; ++i) a[i] ^= 1; }

void solve() {
	int len = 0, x = 0, y = 0;
	bool u, v;
	memset(a, 0, sizeof(a));
	for (int i = 2; i <= 150; i += 2) {
		++len;
		cout << len << endl;
		cin >> a[len];
		cout << b+1-len << endl;
		cin >> a[b+1-len];
		if (!x && a[len] == a[b+1-len]) x = len;
		if (!y && a[len] != a[b+1-len]) y = len;
		if (len == b/2) break;
		if (i % 10 == 0) {
			i += 2;
			cout << (x?x:1) << endl; cin >> u; u = u!=a[x];
			cout << (y?y:1) << endl; cin >> v; v = v!=a[y];
			if (x && y) {
				if (u && v) flip();
				if (u && !v) flip(), rev();
				if (!u && v) rev();
			} else if (x) {
				if (u) flip();
			} else if (y) {
				if (v) rev();
			} else {
				exit(1);
			}
		}
	}
	for (int i = 1; i <= b; ++i) cout << a[i]; cout << endl;
	char c;
	cin >> c;
	if (c == 'N') exit(0);
}

int main() {
	scanf("%d%d", &t, &b);
	for (int i = 1; i <= t; ++i) {
		solve();
	}		
}
