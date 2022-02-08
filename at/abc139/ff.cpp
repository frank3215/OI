#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;

int n, id[maxn];
long long x[maxn], y[maxn], ans;

long long solve() {
	long long ax=0, ay=0, dis=0, tmp;
	random_shuffle(id, id+n);
	for (int i = 0; i < n; ++i) {
		ax += x[id[i]];
		ay += y[id[i]];
		tmp = ax*ax+ay*ay;
		if (tmp > dis) dis = tmp;
		else ax -= x[id[i]], ay -= y[id[i]];
	}
	return dis;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		id[i] = i;
	}
	for (int i = 0; i < 10000; ++i)
		ans = max(ans, solve());
	cout << setprecision(13) << sqrt(ans);
}
