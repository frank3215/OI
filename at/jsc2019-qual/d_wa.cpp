#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;

int n, ans;
int v[maxn], vis[maxn][maxn];
int x[maxn];


void dfs2(int s, int l) {
//	if (s%10 == 0) random_shuffle(x, x+n);
//	printf("%d %d\n", s, l);
	v[s] = 1;
	for (int i = 0; i < n; ++i) {
		if ((!v[i]) && (!vis[s][i])) {
			vis[s][i] = vis[i][s] = l;
			dfs2(i, l);
		}
	}
}
bool dfs1(int k) {
//	printf("%d\n", k);
	if (k == ans) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < i; ++j)
				if (!vis[i][j]) return false;
		return true;
	}
	memset(v, 0, sizeof(v));
	dfs2(rand()%n, k+1);
	return dfs1(k+1);
}


bool check(int u, int l) {
	if (v[u]) return false;
	for (int i = u+1; i < n; ++i) {
		if (vis[u][i] == l && (!check(i, l)) ) return false;
	}
	return true;
}

int main() {
	cin >> n;
//	for (int i = 0; i < n; ++i) i = i;
	ans = (n+1)/2;
	for (int i = 0; i < n; ++i) {
		if (dfs1(0)) {
			for (int i = 0; i < n; ++i) {
				for (int j = i+1; j < n; ++j)
					printf("%d ", vis[i][j]);
				puts("");
			}
			break;
		}
	}
	for (int i = 0; i < n; ++i)
		for (int j = 1; j <= ans; ++j) {
			memset(v, 0, sizeof(v));
			if (!check(i, j)) {
				printf("FUCK %d %d\n", i, j);
			}
		}
}
