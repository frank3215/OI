/*
Check for:
 * natural contraints,
 * long long versus int,
 * off-by-a-char errors: iterator, index, etc
 * natural edge cases,
 */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,b) FOR(i,0,b)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,b) ROF(i,0,b)

const int P = 1e9+7, N = 1005;

int n, m;
char s[N][N];
int g[N][N], tot, fa[N*N];
long long val[N*N];
bool vis[N*N];
vector<int> son[N*N];

int find(int x) {
	return fa[x]?fa[x]=find(fa[x]):x;
}
void merge(int x, int y) {
//	printf("MERGE: %d %d\n", x, y);
	fa[y] = x;
	val[x] = val[x]*val[y]%P;
}

int main() {
	freopen("cave.in", "r", stdin);
	freopen("cave.out", "w", stdout);
	cin >> n >> m;
	F0R(i,n) {
		cin >> s[i];
	}
	R0F(i,n) {
		int cur = 0;
		F0R(j,m) {
			if (s[i][j] == '.') {
				if (s[i+1][j] == '.') {
					int x = find(g[i+1][j]);
//					printf("%d %d: %d\n", i, j, x);
					if (!cur) {
						cur = x;
					}
					if (cur != x) merge(cur, x);
				}
				if (s[i][j+1] == '#') {
//					printf("%d %d: %d\n", i, j+1, cur);
					if (!cur) cur = ++tot, val[cur] = 1;
					for (int k = j; s[i][k] == '.'; --k) g[i][k] = cur;
					cur = 0;
				}
			}
		}
		F0R(j,m) {
			if (s[i][j] == '.' && !fa[g[i][j]]) {
				fa[g[i][j]] = ++tot;
				val[tot] = val[g[i][j]]+1;
			} 
		}
//		F0R(i,tot+1) { printf("%d %d %lld\n", i, fa[i], val[i]); } puts("");
	}
	long long ans = 1;
	FOR(i,1,tot+1) {
		if (!fa[i]) {
			ans = (ans*(val[i]))%P;
		}
	}
	cout << ans << endl;
}
