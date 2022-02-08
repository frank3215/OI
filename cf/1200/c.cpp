#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	return b?gcd(b, a%b):a;
}

ll m, n, g;
int q;

ll area(ll x, ll y) {
	return (y-1)/(x==1?(n/g):(m/g));
}

int main() {
	cin >> n >> m >> q;
	g = gcd(m, n);
	ll sx, sy, ex, ey;
	while (q--) {
		cin >> sx >> sy >> ex >> ey;
		puts((area(sx, sy) == area(ex, ey))?"YES":"NO");
	}
}
