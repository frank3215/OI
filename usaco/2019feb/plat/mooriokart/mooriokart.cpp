#include <cstdio>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7, maxn = 1500+10, maxm = maxn;
typedef long long ll;
int n, m, x, y;
int a, b, d, vis[maxn], K, siz[maxn];
int dp[maxn], ans;
vector<int> v[maxn];
vector<pair<int, int> > g[maxn];
#define v(u,i) g[u][i].first
#define w(u,i) g[u][i].second

int ad(int a, int b, int mod = MOD) { return (a+b)%mod; }
int sub(int a, int b, int mod = MOD) { return (a-b+mod)%mod; }
int mul(int a, int b, int mod = MOD) { return ((ll)a*b)%mod; }
int& DIV2(int &a, int mod = MOD) { return a&1?(a+=MOD)/=2:a/=2; }
int& AD(int& a, int b, int mod = MOD) { return a = ad(a,b,mod); }
int& SUB(int& a, int b, int mod = MOD) { return a = sub(a,b,mod); }
int& MUL(int& a, int b, int mod = MOD) { return a = mul(a,b,mod); }

void con(int a, int b, int d) {
    g[a].push_back(make_pair(b,d));
}
void dfs(int u, int rt, int d) {
    if (!vis[u]) siz[K]++;
    vis[u]++;
    if (u>rt) {
        v[K].push_back(d);
    }
    for (int i = 0; i < g[u].size(); ++i) {
        if (vis[v(u,i)] == vis[u]) continue;
        dfs(v(u,i), u, d+w(u,i));
    }
}
int main() {
    freopen("mooriokart.in", "r", stdin);
    freopen("mooriokart.out", "w", stdout);
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &a, &b, &d);
        con(a,b,d), con(b,a,d);
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d %d\n",i,vis[i]);
        if (!vis[i]) K++;
        dfs(i, i, 0);
    }
    int tot = max(0,y-K*x);
    ans = 1;
/*  if (K > 1) {
        for (int i = 2; i < K; ++i) 
            MUL(ans, i);
        DIV2(ans, 2);
    }*/
    for (int i = 1; i < K; i++, MUL(pow,2));
    for (int i = 1; i <= K; ++i) {
        int sum =;
        for (int j = 0; j < v[i].size(); ++j)
            sum += v[i][j];
        ans += sum;
    }
    for (int i = 1; i <= K; ++i) {
        printf("%d\n",siz[i]);
        if (siz[i] > 1)
            MUL(MUL(ans, siz[i]),siz[i]-1);
    }
    printf("%d\n", ans);
    dp[0] = 1;
    for (int i = 1; i <= K; ++i)
        for (int j = tot-1; ~j; --j) {
            int tmp = 0;
            for (int k = 0; k < v[i].size(); ++k) {
                printf("%d\n",v[i][k]);
                if (v[i][k] <= j)
                    AD(tmp,dp[j-v[i][k]]);
            }
            dp[j]=tmp;
            printf("%d %d %d\n", i, j, dp[j]);
        }
    int pow = 1;
    for (int i = 0; i < tot; ++i) SUB(ans,mul(i,dp[i]));
    printf("%d", MUL(ans,pow));
}
