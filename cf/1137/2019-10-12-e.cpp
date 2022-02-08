#include <bits/stdc++.h>
using namespace std;

const int maxm = 2e5+10;
typedef long long ll;

ll n, X[maxm], P[maxm], B[maxm], S[maxm], t;

ll calc(ll p, ll x, ll b, ll s) { return x+b+s*(p-1); }
void init() { t = 0; P[t] = 1, X[t] = B[t] = S[t] = 0; }
void pop() { B[t-1] += B[t], S[t-1] += S[t]; --t; }
void add(int p, int x) {
	if (x >= B[t]) return;
	while (t > 0) {
		ll x2 = calc(P[t], X[t], B[t], S[t]), p2 = P[t];
		ll x1 = calc(P[t-1], X[t-1], B[t]+B[t-1], S[t]+S[t-1]), p1 = P[t-1];
//		printf("  (%lld, %lld), (%lld, %lld), (%d, %d)\n", p1, x1, p2, x2, p, x);
//		printf("  %lld %lld\n", (p2-p1)*(x-x2), (p-p2)*(x2-x1));
		if ((p2-p1)*(x-x2) <= (p-p2)*(x2-x1)) pop();
		else break;
	}
	++t;
	S[t] = B[t] = 0, X[t] = x, P[t] = p;
}

int main() {
	int m, op, k, b, s;
	scanf("%lld%d", &n, &m);
	init();
	while (m--) {
		scanf("%d", &op);
		switch (op) {
			case 1:
				scanf("%d", &k);
				n += k;
				init();
				break;
			case 2:
				scanf("%d", &k);
				add(n+1, 0);
				n += k;
				break;
			case 3:
				scanf("%d%d", &b, &s);
				B[t] += b;
				S[t] += s;
				b = s = 0;
				while (t > 0 && calc(P[t], X[t], B[t], S[t]) >= calc(P[t-1], X[t-1], B[t-1]+B[t], S[t-1]+S[t])) pop();
				break;
		}
		b = s = 0;
//		for (int i = t; ~i; --i) printf(" %lld %lld\n", P[i], calc(P[i], X[i], b+=B[i], s+=S[i]));
		printf("%lld %lld\n", P[t], calc(P[t], X[t], B[t], S[t]));
	}
}
