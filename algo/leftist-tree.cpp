#include <cstdio>
#include <cstring>
#include <algorithm>
#define __DEBUG 0
const int maxn = 100010;
int n, m, val[maxn];
int fa[maxn], ch[maxn][2], dis[maxn];
int find(int x) {
//	printf(" %d\n", x);
	return (fa[x]>0 && fa[x]!=x)?fa[x]=find(fa[x]):x;
}
int merge(int x, int y) {
	if (!x || !y) return x+y;
	if (val[x] > val[y] || (val[x] == val[y] && x > y)) std::swap(x, y);
	ch[x][1] = merge(ch[x][1], y);
	if (dis[ch[x][1]] > dis[ch[x][0]]) std::swap(ch[x][0], ch[x][1]);
	fa[ch[x][0]] = fa[ch[x][1]] = x;
	dis[x] = dis[ch[x][1]] + 1;
	return x;
}
int pop(int x) {
	fa[x] = -1;
	fa[ch[x][0]] = fa[ch[x][1]] = merge(ch[x][0], ch[x][1]);
	return x;
}
void print() {
	puts("");
	for (int i = 1; i <= n; ++i) {
		printf("%d(%d): %d %d,%d %d\n", i, val[i], fa[i], ch[i][0], ch[i][1], dis[i]);
	}
}
int main() {
#ifdef __LOCAL
	freopen("inp", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	dis[0] = -1;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", val+i);
		fa[i] = i;
	}
	int op, x, y, fx, fy;
	while (m--) {
		scanf("%d%d", &op, &x);
		fx = find(x);
		if (op == 1) {
			scanf("%d", &y);
			fy = find(y);
			if (fx != fy) merge(fx, fy);
		}
		else {
			if (fa[fx] == -1) printf("-1\n");
			else printf("%d\n", val[pop(fx)]);
		}
		if(__DEBUG) print();
	}
}
