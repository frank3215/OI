#include <bits/stdc++.h>
using namespace std;

const int maxp = 2999+10;

int p, a[maxp];
int MOD(int x) { return (x%p+p)%p; }
void mod(int &x) { x = MOD(x); }

int f[maxp], g[maxp], inv[maxp];
int ans[maxp];

void asserts() {
	int tmp = 1;
	for (int i = 1; i < p; ++i) tmp = MOD(tmp*i);
	assert(tmp == p-1);
}

void print(int a[], int n) {
	for (int i = 0; i < n; ++i)
		cout << a[i] << ' ';
	cout << endl;
}

int main() {
	cin >> p;
	asserts();

	inv[1] = 1;
	for (int i = 2; i < p; ++i)
		inv[i] = MOD(-(p/i)*inv[p%i]);

	for (int i = 0; i < p; ++i)
		cin >> a[i];

	f[0] = 1;
	for (int i = 0; i < p; ++i) {
		memset(g, 0, sizeof(g));
		for (int j = 0; j <= p; ++j) {
			mod(g[j] += f[j]*i);
			mod(g[j+1] += f[j]);
		}
		swap(f, g);
	}
//	print(f, p+1);

	for (int i = 0; i < p; ++i) if (a[i]) {
		memset(g, 0, sizeof(g));

		for (int j = p-1; ~j; --j) {
			g[j] = MOD(f[j+1]+i*g[j+1]);
			mod(ans[j]-=g[j]);
		}
//		print(g, p);
	}
	print(ans, p);
}
