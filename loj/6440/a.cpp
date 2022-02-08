#include <bits/stdc++.h>
using namespace std;

const int N = 20, P = 998244353;
typedef long long ll;

ll p, q, r, l;
int n;

struct mat{
	int a[N][N];
	mat(int x = 0, int n = N) {
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
			a[i][j] = i==j?x:0;
	}
	mat operator +(const mat &m) const {
		mat ret;
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
			ret.a[i][j] = (a[i][j]+m.a[i][j])%P;
		return ret;
	}
	mat operator *(const mat &m) const {
		mat ret;
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k)
			ret.a[i][j] = (ret.a[i][j]+(ll)a[i][k]*m.a[k][j])%P;
		return ret;
	}
};
istream& operator >>(istream& in, mat &m) {
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
		in >> m.a[i][j];
	return in;
}
ostream& operator <<(ostream& out, const mat &m) {
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
		out << m.a[i][j] << " \n"[j+1==n];
	return out;
}

struct node{
	mat a, b, s;
	node(): a(1), b(1), s(0) {}
	node(mat A, mat B, mat S) { a = A, b = B, s = S; }
}U, R;
ostream& operator <<(ostream& out, const node &n) {
	return out;
}
node operator *(const node &m, const node &n) {
	node ret = node(m.a*n.a, m.b*n.b, m.s+m.a*n.s*m.b);
	return ret;
}
node qpow(node a, ll x) {
	node ret;
	for (; x; a = a*a, x >>= 1) if (x&1)
		ret = ret*a;
	return ret;
}

mat a, b;

ll div(ll a, ll b, ll c, ll d) {
	assert(d);
	ll ret = ((long double)a*b+c)/d;
	return ret;
}

node solve(ll p, ll q, ll r, ll l, node a, node b) {
	if (l == 0) return node();
	node ret = qpow(a, r/q); r %= q;
	b = qpow(a, p/q)*b; p %= q;
	ll m = div(l, p, r, q);
	if (m == 0) return qpow(b, l);
	ll cnt = l-div(m, q, -r-1, p);
	return ret * qpow(b, (q-r-1)/p) * a * solve(q, p, (q-r-1)%p, m-1, b, a)* qpow(b, cnt);
}

int main() {
	cin >> p >> q >> r >> l >> n;
	cin >> a >> b;
	R.a = R.s = a;
	U.b = b;
	node ans = solve(p, q, r, l, U, R);
	cout << ans.s;
}
