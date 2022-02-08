#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using std::vector;
using std::min;
using std::queue;
const int maxn = 2*200+10, maxm = 2*maxn*maxn;
int n,m,S,T,a;
int s[maxn], ans[maxn];
vector<int> v[maxn][maxn];
struct edge{
    int u, v, w;
    edge(){}
    edge(int U, int V, int W){u=U,v=V,w=W;}
};
struct graph{
    vector<edge> g[maxn];
    int d[maxn];
    void clear() {
        for (int i = 0; i < maxn; ++i) g[i].clear();
    }
    void con(int u, int v, int w) {
        g[u].push_back(edge(v,g[v].size(),w));
        g[v].push_back(edge(v,g[u].size()-1,0));
    }
    void del(int u) {
        g[u].pop_back();
    }
    int bfs() {
        memset(d, 0, sizeof(d));
        d[S] = 1;
        queue<int> q;
        q.push(S);
        while (!q.empty()) {
            int u = q.front();
            for (vector<edge>::iterator e = g[u].begin(); e != g[u].end(); ++e) {
                int v = e->u;
                if (!e->w || d[v]) continue;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
        return d[T];
    }
    int dfs(int u, int b) {
        if (u == T) return b;
        for (vector<edge>::iterator e = g[u].begin(); e != g[u].end(); ++e) {
            if (e->w && d[e->u] == d[u]+1) {
                int d = dfs(e->v, min(b, e->w));
                if (d) {
                    e->w -= d;
                    g[e->u][e->v].w += d;
                    return d;
                }
            }
        }
        return 0;
    }
}g[maxn];
void solve() {
    scanf("%d%d",&n,&m);
    S = n+m+1;
    T = n+m+2;
    int b;
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &b);
        g[0].con(n+i,T,b);
    }
    for (int i = 1; i <= n; ++i) {
        g[i] = g[i-1];
        for (int j = 1; j <= m; ++j) v[i][j].clear();
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &a);
            if(a) v[i][a].push_back(j);
        }
        ans[i] = m+1;
        for (int j = 1; j <= m; ++j) if (v[i][j].size()) {
            for (int k = 0; k < v[i][j].size(); ++k)
                g[i].con(i, v[i][j][k], 1);
            if (g[i].dfs(S, 1)) ans[i] = j;
            for (int k = 0; k < v[i][j].size(); ++k)
                g[i].del(i), g[i].del(v[i][j][k]);
            if (ans[i] != m+1) break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", s+i);
        int l = 0, r = i-1;
        while (l < r) {
            int m = (l+r+1)>>1;
            for (int j = 1; j <= s[i]; ++j) {
                for (int k = 0; k < v[i][j].size(); ++k) {
                    g[m].con(i, v[i][j][k], 1);
                }
            }
            if (g[m].bfs()) l = m;
            else r = m - 1;
        }
        printf("%d ", i-l);
    }
}
int main() {
    int T, C;
    scanf("%d%d", &T, &C);
    while (T--) {
        solve();
    }
}
