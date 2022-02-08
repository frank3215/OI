#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn = 7;
int n,k,m,mx;
int a[maxn],pos[maxn];
int b[maxn],vis[maxn];
bool sorted(int *l) {
	for (int i=1; i<n; ++i) if ( l[i-1] > l[i] ) return false;
	return true;
}
bool shout(int *s,int *l) {
	bool res=0;
	int p[maxn];
	for (int i = 0; i < m; ++i) {
		int cur = 0;
		for (; l[cur] != s[i]; ++cur);
//		printf("(%d:%d)", cur, l[cur]);
		for (; cur != 0 && l[cur] < l[cur-1]; --cur, res = 1) {
			std::swap(l[cur], l[cur-1]);
		}
		for (; cur != n-1 && l[cur] > l[cur+1]; ++cur, res = 1) {
			std::swap(l[cur], l[cur+1]);
		}
	}
	return res;
}
bool check(int *s) {
	int c[maxn];
	memcpy(c,a,sizeof(a));
/*	for (int i = 0; i < m; ++i) {
		printf("%c%d"," \n"[!i],s[i]);
	}
*/
	while (shout(s,c)) {
/*		for (int i=0; i<n; ++i) {
			printf("%c%d", " \n"[!i], c[i]);
		}
*/
	}
	return sorted(c);
}
bool dfs() {
	if(m && check(b)) {
		printf("%d", m);
		for (int i = 0; i < m; ++i) {
			printf("\n%d",b[i]);
		}
		return true;
	}
	if (m==mx) return false;
	for (int i=1; i<=n; ++i) if (!vis[i]) {
		vis[i] = 1;
		b[m++] = i;
		if (dfs()) return true;
		b[--m] = vis[i] = 0;
	}
	return false;
}
int main() {
	freopen("itout.in","r",stdin);
	freopen("itout.out","w",stdout);
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		pos[a[i]] = i;
	}
	for (mx = 1; mx <= n; ++mx) if(dfs()) break;
}
