#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll x, ll y) {
	return y?gcd(y,x%y):x;
}

struct fact{
	ll p, q;
	void norm() {
		ll g = gcd(p, q);
		p /= g;
		q /= g;
	}
}

ostream& operator <<(ostream& out, const fact &f) {
	out << f.p << '/' << f.q;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> q[i];
	}
	for (int i = 1; i <= n; ++i)
		for (int j = i+1; j <= n; ++j) {
			if (a[i] 
		}
}
