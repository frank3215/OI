#include <bits/stdc++.h>
using namespace std;

const int dd[] = {-1, 1, 0, 0}, N = 10, NN = N*N+1, inf = 1e9;
int n, p[NN], P;
int cur[NN], ans[NN], sum=inf, vis[NN];
bool isp[2*NN];

void print(int *ans) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			printf("%d%c", ans[i+j*n], " \n"[j==n-1]);
}

void init() {
	for (int i = 2; i < 2*NN; ++i) {
		isp[i] = 1;
		for (int j = 2; j < i; ++j)
			if (i%j == 0) isp[i] = 0;
	}
}

inline bool prime(int a, int b) { return b==0 || isp[a+b]; }
inline int get(int x, int y) { return (0<=x&&x<n && 0<=y&&y<n)?cur[x+n*y]:0; }
bool ok(int i, int j) {
	for (int k = 0; k < 4; ++k)
		if(!prime(cur[i+j*n], get(i+dd[k], j+dd[3-k])))
			return false;
	return true;
}

bool search(int m, int tmp=0) {
	if (tmp >= sum) return false;
	if (m == n*n) {
		printf("%d\n", tmp);
		sum = tmp;
		memcpy(ans, cur, sizeof(cur));
		return true;
	}
	int x = p[m]%n, y = p[m]/n;
	bool res;
	printf("%d:\n", m, x, y);
//	print(cur);
	for (int i = (x-y)%2 == 0; i <= n*n; i += 2)
		if (!vis[i]) {
			cur[p[m]] = i;
			vis[i] = 1;
//			print(cur);
			if (ok(x, y)) res = search(m+1,tmp + (m<2*n-1)?i:0);
			cur[p[m]] = 0;
			vis[i] = 0;
			if (res && m >= 2*n-1) return true;
		}
	return false;
}

void solve() {
	scanf("%d", &n);
	if (n == 1) {
		puts("NO");
		return;
	}
	for (int i = 1; i < n; ++i) p[++P] = i;
	for (int j = 1; j < n; ++j) p[++P] = j*n;
	for (int i = 1; i < n; ++i)
		for (int j = 1; j < n; ++j)
			p[++P] = i+j*n;
	vis[cur[0]=1] = 1;
	search(1);
	if (sum != inf) print(ans);
	else puts("NO");
}

int main() {
	init();
	solve();
}
