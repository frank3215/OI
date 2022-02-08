#include <bits/stdc++.h>
using namespace std;

namespace {
	const int N = 5e5+10, LOGN = 20;
	int n, m;
	int fa[N][LOGN], dep[N];
	int sa[N], rank[N], sec[N], tmp[N];
	char s[N];
	vector<int> v[N], son[N];

	void print(int *a) {
		for (int i = 1; i <= n; ++i) printf("%d%c", a[i], " \n"[i==n]);
	}
#define print(a) cout<<#a<<": ";print(a)
	bool cmp(int i, int j) {
		return rank[i]<rank[j] || (rank[i]==rank[j]&&i<j);
	}
	void sort() { // {{{1
		for (int i = 0; i <= m; ++i) tmp[i] = 0;
		for (int i = 1; i <= n; ++i) tmp[rank[i]]++;
		for (int i = 1; i <= m; ++i) tmp[i] += tmp[i-1];
		for (int i = n; i >= 1; --i) sa[tmp[rank[sec[i]]]--] = sec[i];
	} // 1}}}
	void solve() { // {{{1
		// Input {{{2
		scanf("%d", &n);
		dep[1] = 0;
		for (int i = 2; i <= n; ++i) {
			scanf("%d", &fa[i][0]);
			son[fa[i][0]].push_back(i);
			dep[i] = dep[fa[i][0]]+1;
		}
		scanf("%s", s+1);
		// Regular SA {{{2
		for (int k = 1; k < LOGN; ++k) {
			for (int i = 1; i <= n; ++i) {
				fa[i][k] = fa[fa[i][k-1]][k-1];
			}
		}
		for (int i = 1; i <= n; ++i) {
			rank[i] = s[i];
			sec[i] = i;
		}
		m = 256;
		sort();
		memcpy(sec, rank, sizeof(rank));
		int p = rank[sa[1]] = 1;
		for (int i = 2; i <= n; ++i) {
			if (sec[sa[i]] != sec[sa[i-1]]) ++p;
			rank[sa[i]] = p;
		}
		m = p;
		for (int k = 0; (1<<k) < n; ++k) {
			p = 0;
			for (int i = 1; i <= n; ++i) v[i].clear();
			for (int i = 1; i <= n; ++i) {
				if (dep[sa[i]] < (1<<k)) sec[++p] = sa[i];
				else v[fa[sa[i]][k]].push_back(sa[i]);
			}
			for (int i = 1; i <= n; ++i) {
				for (int j = 0; j < (int)v[sa[i]].size(); ++j) {
					sec[++p] = v[sa[i]][j];
				}
			}
			sort();
			memcpy(sec, rank, sizeof(rank));
			p = rank[sa[1]] = 1;
			for (int i = 2; i <= n; ++i) {
				if (sec[sa[i]] != sec[sa[i-1]] || sec[fa[sa[i]][k]] != sec[fa[sa[i-1]][k]]) ++p;
				rank[sa[i]] = p;
			}
			m = p;
		}
		// END 2}}}
		// SA On Tree {{{2
		queue<int> q; q.push(1);
		sec[1] = p=1;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			sort(son[u].begin(), son[u].end(), cmp);
			for (int i = 0; i < (int)son[u].size(); ++i) {
				//printf("%d->%d\n", u, son[u][i]);
				q.push(son[u][i]);
				sec[++p] = son[u][i];
			}
		}
		//print(rank);
		//print(sec);
		sort();
		for (int i = 1; i <= n; ++i) printf("%d%c", sa[i], " \n"[i==n]);
		// 2}}}
	} // 1}}}
}

int main() { solve(); }
