#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; --i)
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

const int P = 1e9+7, inv2 = (P+1)/2, inv3 = (P+1)/3;

typedef vector<int> vi;
typedef pair<int,int> pii;

const int QT = 1e6+10;

int prime[QT], v[QT], cnt;
int sp1[QT], sp2[QT];

void pre(int n) {
	FOR(i,2,n+1) {
		if (!v[i]) {
			v[i] = i;
			prime[++cnt] = i;
			sp1[cnt] = (sp1[cnt-1]+i)%P;
			sp2[cnt] = (sp2[cnt-1]+i*i)%P;
		}
		for (int j = 1; j <= cnt && i*prime[j] <= n; ++j) {
			if (prime[j] > v[i]) break;
			v[i*prime[j]] = prime[j];
		}
	}
}

int n, qt;
int w[QT], g1[QT], g2[QT], id1[QT], id2[QT], tot;

int S(int x, int y) {
	if (prime[y] > x) return 0;
	int k = (n/(n/x))<=qt ? id1[n/(n/x)] : id2[n/x];
	int ret = ((g2[k]-g1[k])-(sp2[y]-sp1[y]))%P;
	for (int i = y+1; i <= cnt && prime[i]*prime[i] <= x; ++i) {
		for (int pe = prime[i], e = 1; pe <= x; ++e, pe *= prime[i]) {
			int xx = pe%P;
			ret = (ret+xx*(xx-1)%P*(S(x/pe,i)+(e>1)))%P;
		}
	}
	return ret;
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	scanf("%lld", &n);
	qt = min(n, 100000ll);
	pre(qt);
	for (int l = 1, r; l <= n; l = r+1) {
		r = n/(n/l);
		w[++tot] = r;
		int nr = r%P;
		g1[tot] = (nr%P*(nr+1)%P*inv2-1)%P;
		g2[tot] = (nr%P*(nr+1)%P*inv2%P*((2*nr+1)%P)%P*inv3-1)%P;
		if (r <= qt) id1[r] = tot;
		else id2[n/r] = tot;
	}
	for (int i = 1; i <= cnt; ++i) {
		for (int j = tot; j >= 1 && prime[i]*prime[i] <= w[j]; --j) {
			int k = (w[j]/prime[i]) <= qt ? id1[w[j]/prime[i]] : id2[n/(w[j]/prime[i])];
			g1[j] = (g1[j]-prime[i]*(g1[k]-sp1[i-1]))%P;
			g2[j] = (g2[j]-prime[i]*prime[i]%P*(g2[k]-sp2[i-1]))%P;
		}
	}
	printf("%lld\n", (S(n,0)+1+P)%P);
}

