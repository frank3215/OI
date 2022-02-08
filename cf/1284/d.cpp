#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,b) FOR(i,0,b)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,b) ROF(i,0,b)

#define L first
#define R second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define MOD(x,m) ((x)%(m)+(m))%(m)

typedef pair<int,int> pii;
typedef long long ll;

struct node{
	int l, r, t;
	ll v;
	node *ls, *rs;
	node(int L, int R): l(L), r(R) { v = t = 0, ls = rs = NULL; }
	~node() {
		delete ls;
		delete rs;
	}
	void update(int k) {
		v += (r-l+1ll)*k;
		t += k;
	}
	void pushdown() {
		assert(l != r);
		int m = (l+r)>>1;
		if (!ls) ls = new node(l,m);
		ls->update(t);
		if (!rs) rs = new node(m+1,r);
		rs->update(t);
		t = 0;
	}
	void pushup() {
		assert(ls && rs);
		v = ls->v + rs->v;
	}
	ll range(int L, int R, int k=0) {
//		printf("[%d, %d] %lld %d\n", l, r, v, t);
		if (L <= l && r <= R) {
			update(k);
			return v;
		}
		pushdown();
		int m = (l+r)>>1;
		ll ans = 0;
		if (L <= m) ans += ls->range(L,R,k);
		if (R > m) ans += rs->range(L,R,k);
		pushup();
		return ans;
	}
};

signed main() {
	int n;
	cin >> n;
	pii a[n], b[n];
	F0R(i,n) {
		cin >> a[i].L >> a[i].R >> b[i].L >> b[i].R;
	}
	vector<int> v[n+1];
	bool ans = false;
	F0R(_,2) {
		sort(a, a+n);
		node *seg = new node(1,1e9);
		R0F(i,n) {
			v[ub(a,a+n,mp(a[i].R,0))-a].push_back(i);
		}
		R0F(i,n+1) {
			for (auto j: v[i]) {
//				cout << i << ' ' << j << endl;
				if (seg->range(b[j].L, b[j].R)) ans = true;
			}
			v[i].clear();
			if (i > 0) seg->range(b[i-1].L, b[i-1].R, 1);
		}
		F0R(i,n)
			swap(a[i], b[i]);
		delete seg;
	}
	cout << (ans?"NO":"YES") << endl;
}
