#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
const long double pi = acos(-1.0);

int n;
long double x[maxn], y[maxn], ans;


long double solve() {
	long double r = rand(), nx, ny, ax=0, ay=0;
	r /= RAND_MAX;
	r *= 2*pi;
	for (int i = 0; i < n; ++i) {
		nx = cos(r)*x[i]-sin(r)*y[i];
		ny = sin(r)*x[i]+cos(r)*y[i];
		if (nx >= 0) {
			ax += nx;
			ay += ny;
		}
	}
	return sqrt(ax*ax+ay*ay);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> x[i] >> y[i];
	for (int i = 0; i < 10000; ++i)
		ans = max(ans, solve());
	cout << setprecision(13) << ans;
}
