#include <bits/stdc++.h>
using namespace std;

const int maxm = 3e5+10, maxn = 1e5+10, maxx = maxn+maxm;

int n, m;
int a[maxm], b[maxm], l[maxm];

int siz[maxx], ch[maxx][2], fa[maxx], tot[maxx], rev[maxx];
bool isroot(int x) { return x != ch[fa[x]][0] && x != ch[fa[x]][1]; }
bool which(int x) {
	assert(!isroot(x));
	int w = 
}
int rotate(int x) {
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
}
