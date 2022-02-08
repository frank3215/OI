#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10, L = 22;

int n, fa[L][N];
int sa[N], tx[N], rk[N], rkk[N], rk2[N], tp[N];
char s[N];

inline void tsort(int *sa, int *rk, int *tp, int m) {
	for (int i = 0; i <= m; ++i) tx[i] = 0;
	for (int i = 1; i <= n; ++i) tx[rk[i]]++;
	for (int i = 1; i <= m; ++i) tx[i] += tx[i-1];
	for (int i = n; i; --i) sa[tx[rk[tp[i]]]--] = tp[i];
}

inline bool cmp(int x, int y, int k) {
	return tp[x] == tp[y] && tp[fa[k][x]] == tp[fa[k][y]];
}

int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i) {
		scanf("%d", &fa[0][i]);
		for (int j = 1; j < L; ++j) {
			fa[j][i] = fa[j-1][fa[j-1][i]];
		}
	}
	scanf("%s", s+1);
	for (int i = 1; i <= n; ++i) {
		rk[i] = s[i]-'a';
		tp[i] = i;
	}
	tsort(sa, rk, tp, 26);
	swap(rk, tp);
	int p = rk[sa[1]] = rkk[sa[1]] = 1;
	for (int i = 2; i <= n; ++i) {
		rk[sa[i]] = (tp[sa[i-1]] < tp[sa[i]]) ? ++p : p;
		rkk[sa[i]] = i;
	}
	for (int k = 0; (1<<k) < n; ++k) {
		for (int i = 1; i <= n; ++i) {
			rk2[i] = rkk[fa[k][i]];
		}
		tsort(tp, rk2, sa, n);
		tsort(sa, rk, tp, n);
		swap(rk, tp);
		p = rk[sa[1]] = rkk[sa[1]] = 1;
		for (int i = 2; i <= n; ++i) {
			rk[sa[i]] = (!cmp(sa[i], sa[i-1], k)) ? ++p : p;
			rkk[sa[i]] = i;
		}
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d%c", sa[i], " \n"[i==n]);
	}
}
