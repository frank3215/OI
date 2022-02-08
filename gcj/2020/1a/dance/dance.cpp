#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e3+10, maxm = 1e5+10;

int numR, numC;
int cpre[maxm], cnxt[maxm], rpre[maxm], rnxt[maxm];
int vis[maxm];
int ans, tot;
int a[maxm];

#define id(i,j) ((i)*numC+j)

void solve() {
	cin >> numR >> numC;
	vector<int> modify, pre;
	tot = 0;
	for (int i = 0; i < numR; ++i) {
		for (int j = 0; j < numC; ++j) {
			int k = id(i,j);
			vis[k] = 0;
			cin >> a[k];
			tot += a[k];
			rpre[k] = j!=0?id(i,j-1):-1;
			rnxt[k] = j!=numC-1?id(i,j+1):-1;
			cpre[k] = i!=0?id(i-1,j):-1;
			cnxt[k] = i!=numR-1?id(i+1,j):-1;
			pre.push_back(k);
		}
	}
	ans = 0;
	for (int _ = 1; ; ++_) {
		ans += tot;
		for (int __ = 0; __ < (int)pre.size(); ++__) {
			int i = pre[__];
			if (vis[i]) continue;
			int tmp = 0, cnt = 0;
			if (cpre[i] != -1) tmp+=a[cpre[i]], cnt++;
			if (cnxt[i] != -1) tmp+=a[cnxt[i]], cnt++;
			if (rpre[i] != -1) tmp+=a[rpre[i]], cnt++;
			if (rnxt[i] != -1) tmp+=a[rnxt[i]], cnt++;
			if (cnt && cnt*a[i] < tmp) {
				modify.push_back(i);
				tot -= a[i];
				vis[i] = 1;
			}
		}
		if (!modify.size()) break;
		pre.clear();
		for (int __ = 0; __ < (int)modify.size(); ++__) {
			int i = modify[__];
			if (cpre[i] != -1) {
				cnxt[cpre[i]] = cnxt[i];
				pre.push_back(cpre[i]);
			}
			if (cnxt[i] != -1) {
				cpre[cnxt[i]] = cpre[i];
				pre.push_back(cnxt[i]);
			}
			if (rpre[i] != -1) {
				rnxt[rpre[i]] = rnxt[i];
				pre.push_back(rpre[i]);
			}
			if (rnxt[i] != -1) {
				rpre[rnxt[i]] = rpre[i];
				pre.push_back(rnxt[i]);
			}
		}
		modify.clear();
	}
	cout << ans << endl;
}

signed main() {
	int t;
	cin >> t;
	for (signed i = 1; i <= t; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
}
