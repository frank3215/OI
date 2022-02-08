#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sd(x) scanf("%lld", &x)
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; --i)
#define debug(x) cout << #x << " = " << x << endl
#define FIO(x) \
	freopen(x ".in", "r", stdin); \
	freopen(x ".out", "w", stdout);
#define print(a,n) cout << #a << " = ";_print(a,n);
void _print(int *a, int n) { FOR(i,0,n) printf("%lld%c", a[i], " \n"[i==n-1]); }
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

const int P = 998244353;

int n, m, type;
int nn, _, __, ___;
int a, b, c, id;

int qpow(int a, int x = P-2) {
	int ret = 1;
	for (; x; x >>= 1, a = a*a%P)
		if (x&1) ret = ret*a%P;
	return ret;
}

int f(int x) { return ((a*x+b)%P*x+c)%P; }
void work(int A) {
	int t1 = (A*f(1)%P + (n-A)*f(A+1)%P)%P*_%P,
		t2 = (A*(A-1)%P*f(2)%P + (n-A)*(n-A-1)%P*f(A+2)%P + A*(n-A)%P*(f(1)+f(A+1))%P)%P*__%P,
		t3 = (A*f(A)%P + (n-A)*f(n)%P)%P*_%P;
	a = (t1*(2-n)%P-t2*(1-n)%P-t3)%P*___%P;
	b = (t1*(nn-4)%P+t2*(1-nn)%P+3*t3%P)%P*___%P;
	c = (t1*(4*n-2*nn)%P-t2*(n-nn)%P-2*t3%P)%P*___%P;
}

signed main() {
	FIO("landlords");
	scanf("%lld%lld%lld", &n, &m, &type);
	nn = n*n%P, _ = qpow(n), __ = qpow(n*(n-1)%P), ___ = qpow((3*n-2-nn)%P);
	if (type == 1) a = 0, b = 1, c = 0;
	else a = 1, b = 0, c = 0;
	while (m--) {
		int a;
		scanf("%lld", &a);
		if (a == 0 || a == n) continue;
		work(a);
	}
	scanf("%lld", &m);
	while (m--) {
		int a;
		scanf("%lld", &a);
		printf("%lld\n", (f(a)+P)%P);
	}
}
