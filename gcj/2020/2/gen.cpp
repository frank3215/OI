#include <bits/stdc++.h>
using namespace std;

const int maxn = 110, maxm = 1010;
int dis[maxn], u[maxm], v[maxm], len[maxm], tot, bef[maxn];
set<pair<int,int> > e;

void add(int u, int v) {
	assert(!e.count(make_pair(u,v)));
	e.insert(make_pair(u,v));
	e.insert(make_pair(v,u));
	int w = rand()%10+1;
	++tot;
	::u[tot] = u, ::v[tot] = v;
	len[tot] = w;
}

int main() {
	srand(time(NULL));
	int t = 100;
	printf("%d\n", t);
	while (t--) {
		e.clear();
		int n = 5, m = 10;
		printf("%d %d\n", n, m);
		tot = 0;
		for (int i = 2; i <= n; ++i) {
			add(rand()%(i-1)+1, i);
		}
		for (int i = n; i <= m; ++i) {
			int u, v;
			do {
				u = rand()%n+1, v = rand()%n+1;
			} while (u == v || e.count(make_pair(u, v)));
			add(u, v);
		}
		memset(dis, 0x3f, sizeof(dis));
		dis[1] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				dis[u[j]] = min(dis[u[j]], dis[v[j]]+len[j]);
				dis[v[j]] = min(dis[v[j]], dis[u[j]]+len[j]);
			}
		}
		memset(bef, 0, sizeof(bef));
		for (int i = 2; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) bef[i] += dis[j]<dis[i];
			if (rand()%2) printf("%d ", -bef[i]);
			else printf("%d ", dis[i]);
		} puts("");
		for (int i = 1; i <= m; ++i) {
			printf("%d %d\n", u[i], v[i]);
		}
	}
}
