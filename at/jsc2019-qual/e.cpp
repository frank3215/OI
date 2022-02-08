#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;

int fa[maxn<<1], cnt[maxn<<1];
int find(int x) {
//	printf(" %d %d\n", x, fa[x]);
	return fa[x]>0?fa[x]=find(fa[x]):x;
}
bool merge(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx == fy) {
		if (cnt[fx] == 0) return false;
		cnt[fx]--;
	}
	else {
		if (cnt[fx]+cnt[fy] == 0) return false;
		if (fa[fx] < fa[fy]) swap(fx, fy);
		fa[fx] = fy;
		fa[fy]--;
		cnt[fy] = cnt[fy]+cnt[fx]-1;
	}
	return true;
}

int n, h, w;
pair<int, pair<int, int> > e[maxn];
long long ans = 0;
#define mp make_pair
#define fi first
#define se second

int main() {
	for (int i = 0; i < (maxn<<1); ++i) cnt[i] = 1;
	cin >> n >> h >> w;
	int r, c, a;
	for (int i = 0; i < n; ++i) {
		cin >> r >> c >> a;
		e[i] = mp(a, mp(r, c+h));
	}
	sort(e, e+n);
	reverse(e, e+n);
	for (int i = 0; i < n; ++i) {
		if (merge(e[i].se.fi, e[i].se.se))
			ans += e[i].fi;
	}
	cout << ans << endl;
}
