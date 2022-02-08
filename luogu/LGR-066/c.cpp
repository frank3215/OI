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

const int P = 998244353, K = 5e4+10;

int n, m, k;
int s[K<<1], t[K<<1];
vector<int> v[K<<1];
map<int,int> _m; int tot;

int id(int x) {
	if (!_m.count(x)) _m[x] = tot++;
	return _m[x];
}

int main() {
	cin >> n >> m >> k;
	int a, b; id(1);
	F0R(i,k) {
		cin >> a >> b;
		if (a != b)
			v[id(b)].pb(id(a));
	}
	s[0] = 1;
	while (m--) {
		memcpy(t, s, sizeof(t));
		memset(s, 0, sizeof(s));
		int sum = 0;
		F0R(i,tot+1) sum = (sum+t[i])%P;
		F0R(i,tot) {
			s[i] = (sum-t[i]+P)%P;
			for (auto j : v[i]) {
//				printf("%d:%d %d\n", i, j, t[j]);
				s[i]=(s[i]-t[j]+P)%P;
			}
		}
		s[tot] = (1ll*(sum-t[tot]+P)*(n-tot) + 1ll*(n-tot-1)*t[tot])%P;
//		F0R(i,tot+1) printf("%d%c", s[i], " \n"[i==tot]);
	}
	cout << s[0] << endl;
}
