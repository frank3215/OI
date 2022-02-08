#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;

const int maxlog = 61, P = 998244353, inv2 = (P+1)/2;

vector<pair<int,int> > V[4][maxlog+1], res;

void adda(int x, int L, int R, int l, int r, int dep) {
//	printf("[%lld, %lld]\n", l, r);
	if (L <= l && r <= R) {
//		printf("A: [%lld, %lld]\n", l, r);
		V[x][dep].push_back(make_pair(l, r));
		return;
	}
	V[x^1][dep].push_back(make_pair(l, r));
	int m = (l+r)>>1;
	if (L <= m) adda(x, L, R, l, m, dep+1);
	if (R > m) adda(x, L, R, m+1, r, dep+1);
}

signed main() {
	int na, nb;
	cin >> na;
	int l, r;
	for (int i = 0; i < na; ++i) {
		cin >> l >> r;
		adda(0, l, r, 0, (1ll<<maxlog)-1, 0);
	}
	cin >> nb;
	for (int i = 0; i < nb; ++i) {
		cin >> l >> r;
		adda(2, l, r, 0, (1ll<<maxlog)-1, 0);
	}
	for (int d = 0; d <= maxlog; ++d) {
		for (auto pa : V[0][d])
			for (auto pb : V[2][d]) {
				res.push_back(make_pair(pa.fi^pb.fi, 1));
				res.push_back(make_pair((pa.fi^pb.se)+1, -1));
			}
		for (auto pa : V[0][d])
			for (auto pb : V[3][d]) {
				res.push_back(make_pair(pa.fi^pb.fi, 1));
				res.push_back(make_pair((pa.fi^pb.se)+1, -1));
			}
		for (auto pa : V[1][d])
			for (auto pb : V[2][d]) {
				res.push_back(make_pair(pa.fi^pb.fi, 1));
				res.push_back(make_pair((pa.fi^pb.se)+1, -1));
			}
	}
	sort(res.begin(), res.end());
	int last = 0, cur = 0;
	int ans = 0;
	for (auto p : res) {
		if (cur > 0) {
//			if (last != p.fi) printf("[%lld, %lld]\n", last, p.fi-1);
			(ans += ((p.fi-last)%P)*((p.fi+last-1)%P)%P*inv2) %= P;
		}
		last = p.fi;
		cur += p.se;
	}
	cout << ans << endl;
}
