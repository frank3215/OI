#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int f[N];
bool nop[N];
vector<int> p;

int find(int x) { return f[x] != x ? f[x] = find(f[x]) : x; }

signed main() {
	int a, b, numP;
	scanf("%d%d%d", &a, &b, &numP);
	for (int i = 2; i < N; ++i) {
		if (!nop[i]) {
			p.push_back(i);
		}
		for (int j = 2*i; j < N; j += i) {
			nop[j] = 1;
		}
	}
	for (int i = a; i <= b; ++i) f[i] = i;
	for (auto x: p) if (x >= numP) {
		for (int i = x; i <= b; i += x) {
			if (i-x >= a) f[find(i-x)] = find(i);
		}
	}
	int ans = 0;
	for (int i = a; i <= b; ++i) ans += f[i] == i;
	printf("%d\n", ans);
}
