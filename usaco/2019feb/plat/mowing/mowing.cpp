#include <cstdio>
#include <algorithm>
using namespace std;
#define mp make_pair
const int maxn = 3200+10;
int n, t;
std::pair<int, int> pos[maxn];
long long dp[maxn];
#define x(i) pos[i].first
#define y(i) pos[i].second
// BIT
long long b[maxn];
#define lb(x) (x&-x)
void add(int pos, int mn) {
    for (; pos < n; pos += lb(pos))
        t[pos] = min(t[pos],mn);
}
int query(int pos) {
    long long ans = 1ll<<60;
    for (; pos; pos -= lb(pos))
        ans = min(ans, b[pos]);
}
// SOLVE
int main() {
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    scanf("%d%d", &n, &t);
    for (int i = 2; i <= n+1; ++i) {
        scanf("%d%d", &x(i), &y(i));
    }
    pos[1] = mp(0,0);
    pos[n+2] = mp(t,t);
    sort(pos+2, pos+n+2);
    for (int i = 2; i <= n+2; ++i) {
        dp[i] = 1ll<<60;
        for (int j = 0; j < i; ++j) {
            if (x(j) <= x(i) && y(j) <= y(i)) {
                dp[i] = min(dp[i], dp[j]+(x(i)-x(j))*(y(i)-y(j)));
                printf("%d(%d, %d) %d %lld\n", i, x(i), y(i), j, dp[i]);
            }
        }
    }
    printf("%lld", dp[n+1]);
}

