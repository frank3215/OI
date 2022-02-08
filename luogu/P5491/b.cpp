#include <bits/stdc++.h>
#define int ll
using namespace std;

typedef long long ll;
int t, n, p, a, w;

ostream& operator <<(ostream &, struct p2);

struct p2{
	ll a, b;
	p2 operator *(const p2 &q) {
		return (p2){(a*q.a+b*q.b%p*w)%p, (a*q.b+b*q.a)%p};
	}
	p2 operator %(const int p) {
		return (p2){a%p, b%p};
	}
};

template<typename T>
T qpow(T a, int x, T e) {
	return (x?(qpow(a*a%p, x/2, e)*(x&1?a:e)):e)%p;
}

signed main() {
	cin >> t;
	while (t--) {
		cin >> n >> p;
		int tmp = qpow<ll>(n, (p-1)/2, 1);
		if (tmp == 0) {
			cout << 0 << endl;
			continue;
		} else if (tmp == p-1) {
			cout << "Hola!\n";
			continue;
		}
		do {
			a = rand()%p;
		} while (qpow<ll>(w=((ll)a*a+p-n)%p, (p-1)/2, 1) != p-1);
		p2 x = qpow((p2){a, 1}, (p+1)/2, (p2){1,0});
		cout << min(p-x.a, x.a) << ' ' << max(p-x.a, x.a) << endl;
	}
}
