#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)

typedef unsigned long long ull;

namespace brute{
	const int N = 10, M = 4, inf = 1e9;
	int n, m;
	ull c[N];
	int v[N], a[M], b[M], A[N], B[N];
	int val[N];
	vector<int> xx;
	int ans = inf;
	void dfs(int dep, int cost) {
		if (dep == n) {
			int sumA = 0, sumB = 0;
			FOR(i,0,n) if (A[i]) sumA += val[i];
			FOR(i,0,n) if (B[i]) sumB += val[i];
//			printf("cost=%d, sumA=%d, sumB=%d\nval: ", cost, sumA, sumB);
//			FOR(i,0,n) printf(" %d", val[i]); 
//			putchar('\n');
			FOR(_,0,(int)xx.size()) {
				int i = xx[_];
				int sum = 0;
				FOR(j,0,n) if ((i>>j)&1) sum += val[j];
//				printf(" %d: sum = %d\n", i, sum);
				if (sum < sumA || sum > sumB) return;
			}
			ans = min(ans, cost);
			return;
		}
		FOR(i,1,5) {
			val[dep] = i;
			dfs(dep+1, cost+(val[dep]-v[dep])*(val[dep]-v[dep]));
		}
	}
	void solve() {
		scanf("%d%d", &n, &m);
		FOR(i,0,n) scanf("%llu", c+i);
		FOR(i,0,n) scanf("%d", v+i);
		FOR(i,0,m) {
			scanf("%d", a+i);
//			printf("a[%d] = %d\n", i, a[i]);
			A[a[i]-1] = 1;
		}
		FOR(i,0,m) {
			scanf("%d", b+i);
			B[b[i]-1] = 1;
		}
		FOR(i,0,(1<<n)) {
			int cnt = 0;
			FOR(j,0,n) {
				cnt += (i>>j)&1;
			}
			if (cnt != m) continue;
			//printf("%d\n", i);
			ull xxj[64] = {};
			bool flag = true;
			FOR(j,0,n) if ((i>>j)&1) {
				ull cur = c[j];
				ROF(k,0,64) {
					//printf("%lld %d\n", cur, k);
					if ((cur>>k)&1) {
						cur ^= xxj[k];
						if (!xxj[k]) {
							xxj[k] = cur;
							break;
						}
					}
					//printf("%lld %d\n", cur, k);
					if (!cur) break;
				}
				if (!cur) flag = false;
			}
			if (flag) xx.push_back(i);
		}
		dfs(0,0);
		printf("%d\n", ans);
	}
}

signed main() {
	freopen("shop.in", "r", stdin);
	freopen("shop.out", "w", stdout);
	brute::solve();
}
