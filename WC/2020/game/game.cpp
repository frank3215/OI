#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define mp make_pair
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

const int N = 5e3+10, M = 1e6+3;

int n, p, a[N], b[N];
int head[M], nxt[N];

int query(int x) {
	int y = head[x%M];
	while (y != -1) {
		if (a[y] == x) return y;
		y = nxt[y];
	}
	return -1;
}
void insert(int i) {
	int x = head[a[i]%M], *y = &head[a[i]%M];
	while (x != -1) {
		y = &nxt[x];
		x = nxt[x];
	}
	*y = i;
}

void brute() {
	FOR(i,0,n) {
		insert(i);
	}
	FOR(i,0,n) {
		int x = 1, tmp;
		unordered_map<int,int> vis;
//		debug(a[i]);
		do {
			vis[x] = 1;
			x = 1ll*x*a[i]%p;
			tmp = query(x);
			if (~tmp) {
				b[i] |= 1<<tmp;
			}
//			debug(x); debug(tmp);
		} while (!vis.count(x));
//		debug(b[i]);
	}
	int ans = 0;
	FOR(i,1,1<<n) {
		int ret = n;
		for (int j = i; j; j = (j-1)&i) {
			int cnt = 0, tmp = 0;
			for (int k = 0; k < n; ++k) if (j>>k&1) {
				cnt++;
				tmp |= b[k];
			}
			//debug(i); debug(j); debug(tmp);
			if ((tmp&i) == i) {
				ret = min(ret, cnt);
			}
		}
		ans += ret;
//		debug(i), debug(ret);
	}
	printf("%d\n", ans);
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
#endif
	scanf("%d%d", &n, &p);
	FOR(i,0,n) scanf("%d", a+i);
	memset(head, -1, sizeof(head));
	memset(nxt, -1, sizeof(nxt));
	brute();
}
