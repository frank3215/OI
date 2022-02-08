#include <bits/stdc++.h>
using namespace std;
const int N = 100005, P = 1000000007;
int T, n, m, tot, nxt[2 * N], fst[N], to[2 * N], pw[2 * N], dfn[N], low[N], dfsclk, w[N], bel[N], son[N],
    deg[N], g[N];
bool f[N];
char s[N];
void tarjan(int rt, int u) {
    low[u] = dfn[u] = ++dfsclk;
    bel[u] = rt;
    w[u] = s[u] - '0';
    for (int i = fst[u]; i; i = nxt[i])
        if (!dfn[to[i]]) {
            tarjan(rt, to[i]);
            low[u] = min(low[u], low[to[i]]);
            w[u] += w[to[i]];
            if (low[to[i]] >= dfn[u])
                f[u] |= w[to[i]] & 1, son[u]++, g[u] += w[to[i]];
        } else
            low[u] = min(low[u], dfn[to[i]]);
}
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) deg[i] = fst[i] = g[i] = son[i] = f[i] = dfn[i] = low[i] = 0;
        tot = 0;
        for (int i = 1, u, v; i <= m; i++) {
            scanf("%d%d", &u, &v);
            nxt[++tot] = fst[u];
            fst[u] = tot;
            to[tot] = v;
            nxt[++tot] = fst[v];
            fst[v] = tot;
            to[tot] = u;
            deg[u]++, deg[v]++;
        }
        scanf("%s", s + 1);
        for (int i = pw[0] = 1; i <= m; i++) pw[i] = pw[i - 1] * 2 % P;
        int ans = m - n, c = 0;
        for (int i = 1; i <= n; i++)
            if (!dfn[i])
                tarjan(i, i), ans++, c += w[i] & 1;
        printf("%d", c ? 0 : pw[ans]);
        for (int i = 1; i <= n; i++)
            if (f[i])
                printf(" 0");
            else if (c - (w[bel[i]] & 1))
                printf(" 0");
            else if (w[bel[i]] - (s[i] - '0') - g[i] & 1)
                printf(" 0");
            else
                printf(" %d", pw[ans - deg[i] + (i != bel[i]) + son[i]]);
        puts("");
    }
    return 0;
}
