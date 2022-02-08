#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 4e7+10, maxm = 1e5+10;
int n, type;
int x, y, z, m;
int p[maxm], l[maxm], r[maxm];

ll a[maxn]; int g[maxn];
int id[maxn], qb, qe;

#define f(i) (a[i]-a[g[i]])
#define q(i) (a[id[i]]+f(id[i]))

const ll B = 1e7, N = 3;
struct BigInt{
	ll v[N+1]; int siz;
	BigInt(): v() {}
	void print() {
		if (!siz) printf("0");
		else {
			printf("%lld", v[siz-1]);
			for (int i = siz-2; ~i; --i) {
				printf("%07lld", v[i]);
			}
		}
	}
	BigInt(ll x) {
		siz = 0;
		while (x) {
			v[siz++] = x%B;
			x /= B;
		}
	}
	void norm() {
		ll carry = 0;
		for (int i = 0; i < siz; ++i) {
			v[i] += carry;
			carry = v[i]/B;
			v[i] %= B;
		}
		while (carry) {
			v[siz++] = (carry%B);
			carry /= B;
		}
	}
}ans;

BigInt operator *(const BigInt &a, const BigInt &b) {
	BigInt c;
	c.siz = a.siz+b.siz-1;
	for (int i = 0; i < a.siz; ++i)
		for (int j = 0; j < b.siz; ++j) {
			c.v[i+j] += a.v[i]*b.v[j];
		}
	c.norm();
	return c;
}
BigInt& operator +=(BigInt &a, const BigInt &b) {
	a.siz = max(a.siz, b.siz);
	for (int i = 0; i < N; ++i) {
		a.v[i] += b.v[i];
		a.v[i+1] += a.v[i]/B;
		a.v[i] %= B;
	}
	a.norm();
	return a;
}

void solve() {
	for (int i = 1; i <= n; ++i) {
		a[i] = a[i-1]+a[i];
	}
	a[0] = 0, g[0] = 0;
	id[qe] = 0;
	int cur = 0;
	for (int i = 1; i <= n; ++i) {
		while (cur != qe && q(cur+1) <= a[i]) ++cur;
		g[i] = id[cur];
		while (qe >= qb && q(qe) >= a[i]+f(i)) {
			id[qe--] = 0;
		}
		id[++qe] = i;
	}
	for (int i = n; i != 0; i = g[i]) {
		ans += BigInt(f(i))*BigInt(f(i));
	}
	ans.print();
}

int main() {
	freopen("partition.in", "r", stdin);
	freopen("partition.out", "w", stdout);
	scanf("%d%d", &n, &type);
	if (type == 0) {
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", a+i);
		}
	} else {
		scanf("%d%d%d%lld%lld%d", &x, &y, &z, a+1, a+2, &m);
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d%d", p+i, l+i, r+i);
		}
		for (int i = 3; i <= n; ++i) {
			a[i] = (x*a[i-1] + y*a[i-2] + z) % (1<<30);
		}
		for (int i = 1; i <= m; ++i) {
			for (int j = p[i-1]+1; j <= p[i]; ++j)
				a[j] = a[j]%(r[i]-l[i]+1)+l[i];
		}
	}
	solve();
}
