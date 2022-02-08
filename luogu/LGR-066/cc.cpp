#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,b) FOR(i,0,b)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,b) ROF(i,0,b)

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define MOD(x,m) ((x)%(m)+(m))%(m)

const int P = 998244353, M = 20;

int N;

struct mat{
	int n, m;
	int a[M][M];
	void print() {
		F0R(i,n)
			F0R(j,m)
				printf("%d%c", a[i][j], " \n"[j==m-1]);
	}
	mat(int t = 0) {
		memset(a, 0, sizeof(a));
		if (t == 1) F0R(i,M) a[i][i] = 1;
		else if (t == 2) F0R(i,M) F0R(j,M) a[i][j] = (i != j);
	}
	mat operator *(const mat &M) const {
		assert(m == M.n);
		mat ret;
		ret.n = n, ret.m = M.m;
		F0R(i,n)
			F0R(j,m)
				F0R(k,M.m)
					ret.a[i][k] = (ret.a[i][k]+1ll*a[i][j]*M.a[j][k])%P;
		return ret;
	}
}e(1), t(2);

mat qpow(mat a, int x) {
	if (x == 0) return e;
	else if (x%2 == 1) return qpow(a*a, x/2)*a;
	else return qpow(a*a, x/2);
}

map<int,int> _mp; int tot;
int id(int a) {
	if (!_mp.count(a)) _mp[a] = tot++;
	return _mp[a];
}

int main() {
	int n, m, k, a, b; id(1);
	cin >> n >> m >> k;
	F0R(i,k) {
		cin >> a >> b;
		t.a[id(a)][id(b)] = 0;
	}
	F0R(i,tot) {
		t.a[i][tot] = n-tot;
		t.a[tot][i] = 1;
	}
	t.a[tot][tot] = (n-tot-1);
	t.n = t.m = e.n = e.m = tot+1;
	t.print();
	t = qpow(t, m);
	t.print();
	cout << t.a[id(1)][id(1)] << endl;
}
