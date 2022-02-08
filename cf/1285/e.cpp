#include <bits/stdc++.h>
using namespace std;

const int inf = 20;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,b) FOR(i,0,b)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,b) ROF(i,0,b)

#define ALL(x) x.begin(), x.end()
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ins insert

const int maxx = 1e7;

struct segtree{
	struct node{
		int t, v;
		bool L, R;
		int ls, rs;
		node() {
			v = t = 0;
			ls = rs = 0;
			L = R = 0;
		}
	}t[maxx];
	int tot;
	void update(int u, int k, int l, int r) {
		t[u].t += k;
		if (t[u].t) {
			t[u].v = t[u].L = t[u].R = 1;
		} else {
			if (l == r) {
				t[u].v = t[u].L = t[u].R = 0;
				return;
			}
			pushup(u);
		}
	}
	void pushup(int u) {
		if (t[u].t) return;
		t[u].L = t[t[u].ls].L;
		t[u].R = t[t[u].rs].R;
		t[u].v = t[t[u].ls].v + t[t[u].rs].v - (t[t[u].ls].R && t[t[u].rs].L);
	}
	int range(int &u, int L, int R, int l, int r, int k=0) {
		if (!u) u = ++tot;
		if (L <= l && r <= R) {
			update(u, k, l, r);
			return t[u].v;
		}
		int ans = 0;
		int m = (l+r)>>1;
		if (L <= m) ans += range(t[u].ls,L,R,l,m,k);
		if (R > m) ans += range(t[u].rs,L,R,m+1,r,k);
		pushup(u);
		return ans;
	}
}seg;

int rt = 0;

void solve() {
	int n;
	cin >> n;
	int a[n], b[n];
	vector<int> v;
	F0R(i,n) {
		cin >> a[i] >> b[i];
		a[i] = a[i]*2;
		b[i] = b[i]*2;
		v.pb(a[i]), v.pb(b[i]), v.pb(a[i]-1), v.pb(b[i]+1);
	}
	sort(ALL(v));
	v.erase(unique(ALL(v)), v.end());
	F0R(i,n) {
		a[i] = lb(ALL(v), a[i])-v.begin();
		b[i] = lb(ALL(v), b[i])-v.begin();
	}
	F0R(i,n) seg.range(rt, a[i], b[i], 0, v.size()-1, 1);
	int ret = 0;
	F0R(i,n) {
		seg.range(rt, a[i], b[i], 0, v.size()-1, -1);
		ret = max(ret, seg.range(rt, 0, v.size()-1, 0, v.size()-1));
		seg.range(rt, a[i], b[i], 0, v.size()-1, 1);
	}
	FOR(i,1,seg.tot+1) seg.t[i] = segtree::node();
	seg.tot = rt = 0;
	cout << ret << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
